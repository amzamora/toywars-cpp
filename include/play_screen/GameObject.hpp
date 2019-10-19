#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "Window.hpp"

enum GameObjectType {
	TANK,
	ROCKS,
	WATER
};

class GameObject {
public:
	// Data
	enum GameObjectType type;

	// Methods
	virtual ~GameObject() {};
	virtual void draw(Window *window, SDL_Rect dst) = 0;
	virtual void update() = 0;
};


#endif
