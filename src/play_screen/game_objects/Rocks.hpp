#ifndef ROCKS_HPP
#define ROCKS_HPP

#include "../GameObject.hpp"

class Rocks : public GameObject {
public:
	// Data
	const char* texture = "assets/atlas.png";
	const int cx = 0;  // X coordinate where to clip the texture
	const int cy = 0;    // Y coordinate where to clip the texture
	const int tw = 32;  // Texture width
	const int th = 32;  // Texture height

	// Methods
	Rocks();
	~Rocks();
	void draw(Window *window, SDL_Rect dst) override;
	void update() override;

};

#endif
