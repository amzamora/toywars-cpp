#ifndef INPUT_HPP
#define INPUT_HPP

class Input {
public:
        bool left;
        bool right;
        bool up;
        bool down;
        unsigned int zoom_in;
        unsigned int zoom_out;

        Input() {
                left = false;
                right = false;
                up = false;
                down = false;
                zoom_in = 0;
                zoom_out = 0;
        }
};

#endif
