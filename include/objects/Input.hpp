#ifndef INPUT_HPP
#define INPUT_HPP

class Input {
public:
        bool left;
        bool right;
        bool up;
        bool down;
        int scroll;

        Input() {
                left = false;
                right = false;
                up = false;
                down = false;
                scroll = 0;
        }
};

#endif
