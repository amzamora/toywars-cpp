#ifndef GameObject_hpp
#define GameObject_hpp

#include <vector>

//#include "game_objects/Tank.hpp"
//#include "game_objects/Mountain.hpp"
//#include "game_objects/Lake.hpp"

class GameObject {
	public:
		void update(Board *board);
		void draw();

		//static Tank *new_tank(int row, int column);

	private:
		int row;
		int column;
		SDL_Texture* texture;
		std::vector<Component*> components;
};

#endif
