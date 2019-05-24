#ifndef INPUT_HPP
#define INPUT_HPP

class Input {
public:
        bool left;
        bool right;
        bool up;
        bool down;

        Input() {
                left = false;
                right = false;
                up = false;
                down = false;
        }
};

#endif
