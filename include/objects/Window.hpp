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

class Window {
public:
	// Data
	SDL_Window* window;
	SDL_GLContext context;
	map<string, SDL_Texture*> textures;

	// Methods
	Window(const char *title, int x, int y, int width, int height, bool fullscreen);
	~Window() {};

	void draw(const char* texture_path, SDL_Rect clip, SDL_Rect dst);
	void update();
	void clear();
	void close();

	void load_texture(const char *path);
};

#endif
