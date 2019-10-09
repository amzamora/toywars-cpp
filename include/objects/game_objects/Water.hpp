#ifndef WATER_HPP
#define WATER_HPP

#include "objects/GameObject.hpp"

class Water : public GameObject {
public:
	// Data
	const char* texture = "assets/atlas.png";
	const int cx = 32;  // X coordinate where to clip the texture
	const int cy = 0;    // Y coordinate where to clip the texture
	const int tw = 32;  // Texture width
	const int th = 32;  // Texture height

	const int topmost_cx = 64;  // X coordinate where to clip the texture
	const int topmost_cy = 0;    // Y coordinate where to clip the texture
	const int topmost_w = 32;  // Texture width
	const int topmost_h = 32;  // Texture height

	bool topmost = false;

	// Methods
	Water();
	~Water();
	void draw(Window *window, SDL_Rect dst) override;
	void update() override;

};

#endif
