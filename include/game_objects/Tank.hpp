#ifndef Tank_hpp
#define Tank_hpp

#include "GameObject.hpp"

class Tank : public GameObject {
	public:
		Tank(int row, int column):GameObject(row, column, 128, 128, 256, 0) {};
		~Tank();

		void draw();
};

#endif
