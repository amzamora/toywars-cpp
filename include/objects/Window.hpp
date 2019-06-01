#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include "SDL2/SDL.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Window {
public:
	// Data
	SDL_Window* window;
	SDL_GLContext context;
	map<string, unsigned int> textures;
	int shader_program;
	unsigned int VAO;
	unsigned int vert_buffer;


	// Methods
	Window(const char *title, int x, int y, int width, int height, bool fullscreen);
	~Window();

	void clear();
	void update();
	void close();
	void load_texture(const char *path);
	void render(const char* texture_path, SDL_Rect clip, SDL_Rect dst);
};

#endif
