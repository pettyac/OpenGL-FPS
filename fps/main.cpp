//File: main.cpp

#include <iostream>
#include <GL/freeglut.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include "mygllib3d/gl3d.h"
#include <glm/glm.hpp>

float lastX = mygllib::WIN_W;
float lastY = mygllib::WIN_H;
mygllib::Light & light = *(mygllib::Singleton<mygllib::Light>::getInstance());

void init()
{
    mygllib::Camera & camera = *(mygllib::Singleton<mygllib::Camera>::getInstance());
    
	camera.set_projection();
	camera.camlookat();
    light.set(GL_LIGHT0);
    glutInitDisplayMode(GLUT_DEPTH);
	glViewport(0, 0, 400, 400);
	glEnable(GL_DEPTH_TEST);	
	glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
}

void display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	static float p[8][3] = {{0, 1, 1},
                            {1, 1, 1},
                            {1, 0, 1},
                            {0, 0, 1},
                            {0, 1, 0},
                            {1, 1, 0},
                            {1, 0, 0},
                            {0, 0, 0}};

    static float n[6][3] = {{0, 1, 1},
                            {1, 0, 0},
                            {0, 0, -1},
                            {-1, 0, 0},
                            {0, 1, 0},
                            {0, -1, 0}};

    light.all_on();
	glBegin(GL_QUADS);
    {
        glColor3f(0, 0, 1);

        // Back
        glNormal3fv(n[2]);
        glVertex3fv(p[7]);
        glVertex3fv(p[4]);
        glVertex3fv(p[5]);
        glVertex3fv(p[6]);

        /*
        // Right
        glNormal3fv(n[1]);
        glVertex3fv(p[2]);
        glVertex3fv(p[6]);
        glVertex3fv(p[5]);
        glVertex3fv(p[1]);
        */


        // Front
        glNormal3fv(n[0]);
        glVertex3fv(p[3]);
        glVertex3fv(p[2]);
        glVertex3fv(p[1]);
        glVertex3fv(p[0]);



        // Left
        glNormal3fv(n[3]);
        glVertex3fv(p[3]);
        glVertex3fv(p[0]);
        glVertex3fv(p[4]);
        glVertex3fv(p[7]);

        glColor3f(1, 0, 0);
        // Top
        glNormal3fv(n[4]);
        glVertex3fv(p[0]);
        glVertex3fv(p[1]);
        glVertex3fv(p[5]);
        glVertex3fv(p[4]);
        
        glColor3f(0, 1, 0);
	   // Bottom
	    glNormal3fv(n[5]);
        glVertex3fv(p[7]);
        glVertex3fv(p[6]);
        glVertex3fv(p[2]);
        glVertex3fv(p[3]);
    }
	glEnd();
    
    light.all_off();
	mygllib::draw_xz_plane();
	//mygllib::draw_axes();
	glutSwapBuffers();
}

int main(int argc, char ** argv)
{
	mygllib::init3d();	
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(mygllib::Reshape::reshape);
	glutKeyboardFunc(mygllib::Keyboard::keyboard);
    glutMouseFunc(mygllib::Mouse::mouse);
    glutPassiveMotionFunc(mygllib::Mouse::passive_motion);
    glutMotionFunc(mygllib::Mouse::motion);
    glutEntryFunc(mygllib::Mouse::entry);
	glutMainLoop();

	return 0;
}
