#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <map>
#include <string>
using namespace std;

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Window {
public:
        // Data
        SDL_Window* window;
	SDL_Renderer *renderer;
        map<string, SDL_Texture*> textures;


        // Methods
        Window(const char *title, int x, int y, int width, int height, bool fullscreen);
        ~Window();

        void clear();
        void update();
        void close();
        void load_texture(const char *path);
        void render(const char* texture_path, int cx, int cy, int cw, int ch, int x, int y, int w, int h);
};

#endif
