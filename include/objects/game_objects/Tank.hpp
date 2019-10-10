#ifndef TANK_HPP
#define TANK_HPP

#include "objects/GameObject.hpp"

class Tank : public GameObject {
public:
	// Data
	const char* texture = "assets/atlas.png";
	const int cx = 0;  // X coordinate where to clip the texture
	const int cy = 96;    // Y coordinate where to clip the texture
	const int tw = 32;  // Texture width
	const int th = 32;  // Texture height

	enum Direction direction;

	// Methods
	Tank(enum Direction direction);
	~Tank();
	void draw(Window *window, SDL_Rect dst) override;
	void update() override;

};

#endif
