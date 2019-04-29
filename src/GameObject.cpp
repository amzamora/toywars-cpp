#include "GameObject.hpp"

GameObject::GameObject(int row, int column, int width, int height, int texture_x, int texture_y) {
	this->row = row;
	this->column = column;
	this->width = width;
	this->height = height;
	this->texture_x = texture_x;
	this->texture_y = texture_y;
}

GameObject::~GameObject() {};
