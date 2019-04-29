#ifndef GameObject_hpp
#define GameObject_hpp

#include <vector>
#include "SDL2/SDL.h"

class GameObject {
	public:
		GameObject(int row, int column, int width, int height, int texture_x, int texture_y);
		virtual ~GameObject();
		//void update(Board *board);
		virtual void draw() {};

	protected:
		int row;
		int column;
		int width;
		int height;
		int texture_x;
		int texture_y;
		//std::vector<Component*> components;
};

#endif
