#ifndef MOUSE_H
#define MOUSE_H

namespace mygllib
{
    class Mouse
    {
        public:
            static void mouse(int, int, int, int);
            static void motion(int x, int y);
            static void passive_motion(int x, int y);
            static void entry(int state);
        
            static int x()       { return x_; }
            static int y()       { return y_; }

            static bool mouse_down()         { return mouse_down_; }

        private:
            static int x_, y_;
            static bool mouse_down_;
            static float sensitivity;
    };
}

#endif
 
