#include "objects/Window.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

/* Useful functions
   =================== */
string get_text(string path) {
	string res, str = "";

	ifstream in;
	in.open (path.c_str());
	if (in.is_open()) {
		getline (in, str);
		while (in) {
			res += str + "\n";
			getline (in, str);
		}
		return res;
	} else {
		cerr << "Unable to open file \"" << path << "\"\n";
		throw 2;
	}
}

static unsigned int load_shader(string path) {
	string source = get_text(path);

	// Get type of shader
	unsigned int shader;
	if (path.substr(path.find_last_of (".") + 1) == "vert") {
		shader = glCreateShader(GL_VERTEX_SHADER);

	} else {
		shader = glCreateShader(GL_FRAGMENT_SHADER);
	}

	// Compile shader
	const char *source_as_c_str = source.c_str();
	glShaderSource(shader, 1, &source_as_c_str, NULL);
	glCompileShader(shader);

	// Check if was compiled correctly
	int  success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if(!success) {
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		cout <<  "Shader in \"" << path << "\" could not be compilated :(\n";
	}

	return shader;
}


/* Window
   ====== */

Window::Window(const char *title, int x, int y, int width, int height, bool fullscreen) {
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
	window = SDL_CreateWindow(title, x, y, width, height, flags);

	if (window == NULL) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	// Create context
	context = SDL_GL_CreateContext(window);
	if(context == NULL) {
		printf( "Context could not be created! SDL Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	// Load OpenGL functions
	gladLoadGLLoader(SDL_GL_GetProcAddress);

	// V-Sync
	SDL_GL_SetSwapInterval(1);

	// Create shader program
	unsigned int vertex_shader = load_shader("shaders/vertex_shader.vert");
	unsigned int fragment_shader = load_shader("shaders/fragment_shader.frag");
	this->shader_program = glCreateProgram();
	glAttachShader(this->shader_program, vertex_shader);
	glAttachShader(this->shader_program, fragment_shader);
	glLinkProgram(this->shader_program);
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);


	// Define data
	// -----------
	float vertices[] = {
	    // positions         // colors           // texture coords
	    0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
	    0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
	   -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
	   -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left
	};
	unsigned int indices[] = {
	    0, 1, 3, // first triangle
	    1, 2, 3  // second triangle
	};

	// Create Vertex Array Object to store configuration
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// Create buffer in VRAM for vertices
	unsigned int vert_buffer;
	glGenBuffers(1, &vert_buffer); // Create vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, vert_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // Put data on the buffer

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0); // Specify layout of positions
	glEnableVertexAttribArray(0);  // Tell OpenGL we can use location 0 in shaders

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3*sizeof(float))); // Specify layout of colors
	glEnableVertexAttribArray(1); // Tell OpenGL we can use location 1 in shaders

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6*sizeof(float))); // Specify layout of texture coordinates
	glEnableVertexAttribArray(2); // Tell OpenGL we can use location 1 in shaders

	// Create buffer in VRAM for indices
	unsigned int ind_buffer;
	glGenBuffers(1, &ind_buffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ind_buffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Load texture
	load_texture("assets/texture_atlas.png");

	glUniform1i(glGetUniformLocation(shader_program, "ourTexture"), 0); // set it manually
}

Window::~Window() {

}


void Window::clear() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(shader_program);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures["assets/texture_atlas.png"]);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Window::update() {
	SDL_GL_SwapWindow(window);
}

void Window::close() {
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Window::load_texture(const char* path) {
	unsigned int texture;

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	// Set texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Load image
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	} else {
		cout << "Failed to load texture :(\n";
	}
	stbi_image_free(data);

	textures.insert(pair<string, unsigned int>(path, texture));
}

void Window::render(const char* texture_path, SDL_Rect clip, SDL_Rect dst) {
	//SDL_RenderCopy(renderer, textures[texture_path], &clip, &dst);
}
