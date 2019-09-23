#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <map>
#include <string>
using namespace std;

#include "SDL2/SDL.h"
#include <deps/glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct Texture {
	unsigned int id;
	float width;
	float height;
};

class Window {
public:
	// Data
	float width;
	float height;

	SDL_Window* window;
	SDL_GLContext context;

	unsigned int shader_program;
	map<string, struct Texture> textures;

	// Methods
	Window(const char *title, int x, int y, int width, int height, bool fullscreen);
	~Window() {};

	void draw(const char* texture_path, SDL_Rect clip, SDL_Rect dst, float rotation = 0);
	void update();
	void clear();
	void close();

	void load_texture(const char *path);
};

#endif
