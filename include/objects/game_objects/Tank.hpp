#ifndef TANK_HPP
#define TANK_HPP

#include "objects/GameObject.hpp"

class Tank : public GameObject {
public:
	// Data
	const char* texture = "assets/atlas.png";
	const int cx = 96;  // X coordinate where to clip the texture
	const int cy = 0;    // Y coordinate where to clip the texture
	const int tw = 32;  // Texture width
	const int th = 32;  // Texture height

	// Methods
	Tank();
	~Tank();
	void draw(Window *window, SDL_Rect dst) override;
	void update() override;

};

#endif
