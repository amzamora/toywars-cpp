#include "objects/Window.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <deps/stb_image.h>

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
}

void Window::clear() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::update() {
	SDL_GL_SwapWindow(window);
}

void Window::close() {
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Window::draw(const char* texture_path, SDL_Rect clip, SDL_Rect dst) {

}

void Window::load_texture(const char *path) {

}
