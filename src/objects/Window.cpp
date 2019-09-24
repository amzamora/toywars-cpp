#include "objects/Window.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <deps/stb_image.h>

#include <vector>

/* Window
   ====== */

Window::Window(const char *title, int x, int y, int width, int height, bool fullscreen) {
	this->width = width;
	this->height = height;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}


	// Request an OpenGL 4.5 context (should be core)
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);


	// Create window
	unsigned int flags = fullscreen ?  SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN : SDL_WINDOW_OPENGL;
	this->window = SDL_CreateWindow(title, x, y, width, height, flags);

	if (this->window == NULL) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		exit(EXIT_FAILURE);
	}


	// Create context
	this->context = SDL_GL_CreateContext(window);
	if(this->context == NULL) {
		printf( "Context could not be created! SDL Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(this->window);
		SDL_Quit();
		exit(EXIT_FAILURE);
	}


	// Load OpenGL functions
	gladLoadGLLoader(SDL_GL_GetProcAddress);


	// V-Sync
	SDL_GL_SetSwapInterval(1);


	// Create shader
	const char* vertex_shader =
	"#version 400\n"
	"layout (location = 0) in vec3 pos;"
	"layout (location = 1) in vec2 aTexCoord;"
	"out vec2 texCoord;"
	"uniform mat4 transform;"
	"void main() {"
	"  gl_Position = transform * vec4(pos.x, pos.y, -1.0, 1.0);"
	"  texCoord = aTexCoord;"
	"}";

	const char* fragment_shader =
	"#version 400\n"
	"in vec2 texCoord;"
	"uniform vec4 ourColor;"
	"uniform sampler2D ourTexture;"
	"out vec4 texColor;"
	"void main() {"
	"  texColor = texture(ourTexture, texCoord);"
	//"    texColor = vec4(0.0, 0.0, 0.0, 1.0);"
	"}";

	int success;

	unsigned int vs;
	vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	glGetShaderiv(vs, GL_COMPILE_STATUS, &success);
	if (!success) {printf("Error while compiling vertex shader :c\n");}

	unsigned int fs;
	fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);
	glGetShaderiv(fs, GL_COMPILE_STATUS, &success);
	if (!success) {printf("Error while compiling fragment shader :c\n");}

	this->shader_program = glCreateProgram();
	glAttachShader(shader_program, vs);
	glAttachShader(shader_program, fs);
	glLinkProgram(shader_program);

	glDeleteShader(vs);
	glDeleteShader(fs);


	// GL Settings
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Window::clear() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::update() {
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// Put vertices on GPU
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	// Specify layout of vertices
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*) 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// Put indices in GPU
	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * indices.size(), &indices[0], GL_STATIC_DRAW);

	// Model matrix
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::scale(model, glm::vec3(1.0f, -1.0f, 1.0f));
	model = glm::translate(model, glm::vec3(0.0, -this->height, 0.0f));

	// Projection matrix
	glm::mat4 proj = glm::mat4(1.0f);
	proj = glm::ortho(0.0f, this->width, 0.0f, this->height, 0.1f, 100.0f);

	glm::mat4 trans = proj * model /** glm::scale(glm::mat4(1.0f), glm::vec3(dst.w/100.0f, dst.h/100.0f, 1.0f))*/;

	unsigned int transform_loc = glGetUniformLocation(shader_program, "transform");
	glUniformMatrix4fv(transform_loc, 1, GL_FALSE, glm::value_ptr(trans));

	glBindVertexArray(VAO);
	glUseProgram(this->shader_program);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

	SDL_GL_SwapWindow(window);

	this->vertices.clear();
	this->indices.clear();
}

void Window::close() {
	SDL_GL_DeleteContext(this->context);
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}

void Window::draw(const char* texture_path, SDL_Rect clip, SDL_Rect dst, float rotation) {
	// If not loaded
	// -------------
	if (textures.find(texture_path) == textures.end()) {
		printf("Texture not loaded >:c\n");
		load_texture(texture_path);
	}

	struct Texture t = this->textures[texture_path];

	// Draw stuff
	// ----------

	// Add geometry
	// ------------

	// Top right
	this->vertices.push_back(dst.x + dst.w);
	this->vertices.push_back(dst.y);
	this->vertices.push_back(1.0);
	this->vertices.push_back(0.0);

	// Bottom right
	this->vertices.push_back(dst.x + dst.w);
	this->vertices.push_back(dst.y + dst.h);
	this->vertices.push_back(1.0);
	this->vertices.push_back(1.0);

	// Bottom left
	this->vertices.push_back(dst.x);
	this->vertices.push_back(dst.y + dst.h);
	this->vertices.push_back(0.75);
	this->vertices.push_back(1.0);

	// Top left
	this->vertices.push_back(dst.x);
	this->vertices.push_back(dst.y);
	this->vertices.push_back(0.75);
	this->vertices.push_back(0.0);

	// Add indices
	// -----------

	unsigned int offset = 0;
	if (this->indices.size() != 0) {
		offset = this->indices[this->indices.size() - 1] + 1;
	}

	// First triangle
	this->indices.push_back(offset + 0);
	this->indices.push_back(offset + 1);
	this->indices.push_back(offset + 3);

	// Second triangle
	this->indices.push_back(offset + 1);
	this->indices.push_back(offset + 2);
	this->indices.push_back(offset + 3);
}

void Window::load_texture(const char *path) {
	// Load image
	int width, height, nrChannels;
	//stbi_set_flip_vertically_on_load(true);
	unsigned char *data = stbi_load(realpath(path, NULL), &width, &height, &nrChannels, 0);

	// Create texture
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

	struct Texture t;
	t.id = texture;
	t.width = width;
	t.height = height;

	textures.insert(pair<string, struct Texture>(path, t));

	// Free stuff
	stbi_image_free(data);
}
