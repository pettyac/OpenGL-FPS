#include "Mouse.h"
#include <GL/freeglut.h>
#include <iostream>
#include "config.cpp"


void mygllib::Mouse::mouse(int button, int state, int x_, int y_)
{
    x() = x_;
    y() = 400 - y_;
    mouse_down() = (state == GLUT_DOWN);
    switch (button)
    {
        case GLUT_LEFT_BUTTON: std::cout << "left" << std::endl; break;
        case GLUT_MIDDLE_BUTTON: std::cout << "mid" << std::endl; break;
        case GLUT_RIGHT_BUTTON: std::cout << "right" << std::endl; break;
    }
    glutPostRedisplay();
}

void mygllib::Mouse::motion(int x_, int y_)
{
    x() = x_;
    y() = mygllib::WIN_H - y_;
    glutPostRedisplay();
}

void mygllib::Mouse::passive_motion(int x_, int y_)
{
    x() = x_;
    y() = mygllib::WIN_H - y_;
    glutPostRedisplay();
}

void mygllib::Mouse::entry(int state)
{
    glutPostRedisplay();
}


