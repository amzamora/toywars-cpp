#ifndef WATER_HPP
#define WATER_HPP

#include "objects/GameObject.hpp"

class Water : public GameObject {
public:
        // Data
        const char* texture = "assets/texture_atlas.png";
        const int cx = 128;  // X coordinate where to clip the texture
        const int cy = 0;    // Y coordinate where to clip the texture
        const int tw = 128;  // Texture width
        const int th = 128;  // Texture height

        // Methods
        Water(int row, int column);
        ~Water();
        void draw(Window *window, SDL_Rect dst) override;
        void update() override;

};

#endif
