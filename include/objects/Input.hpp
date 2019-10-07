#ifndef INPUT_HPP
#define INPUT_HPP

class Input {
public:
        bool left;
        bool right;
        bool up;
        bool down;

        int scroll;
        int mouse_x;
        int mouse_y;

        Input() {
                left = false;
                right = false;
                up = false;
                down = false;
                scroll = 0;
                mouse_x = 0;
                mouse_y = 0;
        }
};

#endif
