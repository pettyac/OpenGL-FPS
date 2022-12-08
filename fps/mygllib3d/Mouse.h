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
        
            int & x()       { return x_; }
            int & y()       { return y_; }

            bool & mouse_down()         { return mouse_down_; }

        private:
            int x_, y_;
            bool mouse_down_;
    };
}

#endif
 
