#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "SDL2/SDL.h"

class Window {
public:
        // Data
        SDL_Window* window;
	SDL_Renderer *renderer;

        // Methods
        Window(const char *title, int x, int y, int width, int height, bool fullscreen);
        ~Window();

        void clear();
        void update();
        void close();
};

#endif
