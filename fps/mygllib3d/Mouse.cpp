#include "Mouse.h"
#include <GL/freeglut.h>
#include <iostream>
#include "config.h"
#include "Camera.h"
#include "gl3d.h"

bool mygllib::Mouse::mouse_down_;
int mygllib::Mouse::x_ = mygllib::WIN_W / 2;
int mygllib::Mouse::y_ = mygllib::WIN_H / 2;
float mygllib::Mouse::sensitivity = 0.4f;
bool firstMouse = true;


void mygllib::Mouse::mouse(int button, int state, int x, int y)
{
    x_ = x;
    y_ = WIN_Y - y;
    mouse_down_ = (state == GLUT_DOWN);
    switch (button)
    {
        case GLUT_LEFT_BUTTON: break;
        case GLUT_MIDDLE_BUTTON: break;
        case GLUT_RIGHT_BUTTON: break;
    }
    glutPostRedisplay();
}

void mygllib::Mouse::motion(int x, int y)
{
    mygllib::Camera & camera = *(mygllib::Singleton<mygllib::Camera>::getInstance());
    
    x *= sensitivity;
    y *= sensitivity;

    camera.yaw() += x;
    camera.pitch() += y;
    
    if (camera.pitch() > 89.0f) camera.pitch() = 89.0f;
    if (camera.pitch() < -89.0f) camera.pitch() = -89.0f;

    camera.setCamera();
    camera.set_projection();
    camera.camlookat();
    glutPostRedisplay();
}

void mygllib::Mouse::passive_motion(int x, int y)
{
    mygllib::Camera & camera = *(mygllib::Singleton<mygllib::Camera>::getInstance());
    
    if (firstMouse)
    {
        x_ = x;
        y_ = y;
        firstMouse = false;
    }
    float xoffset = x - x_;
    float yoffset = y_ - y;
    x_ = x;
    y_ = y;

    xoffset *= sensitivity;
    yoffset *= sensitivity;
    camera.yaw() += xoffset;
    camera.pitch() += yoffset;
    
    if (camera.pitch() > 89.0f) camera.pitch() = 89.0f;
    if (camera.pitch() < -89.0f) camera.pitch() = -89.0f;

    camera.setCamera();
    camera.set_projection();
    camera.camlookat();
    glutPostRedisplay();
}

void mygllib::Mouse::entry(int state)
{
    glutPostRedisplay();
}