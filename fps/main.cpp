//File: main.cpp

#include <iostream>
#include <GL/freeglut.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include "mygllib3d/gl3d.h"
#include <glm/glm.hpp>

GLboolean light_on;
GLfloat light_ambient[4];
GLfloat light_diffuse[4];
GLfloat light_specular[4];
GLfloat light_position[4];
glm::mat4 view_;
float camX, camZ;
float radius;

void init1()
{
    mygllib::Camera & camera = *(mygllib::SingletonView::getInstance());
    
	camera.set_projection();
	camera.lookat();
    glutInitDisplayMode(GLUT_DEPTH);
	glViewport(0, 0, 400, 400);
	glEnable(GL_DEPTH_TEST);	
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glColor3f(0, 0, 1);
}

void init2()
{
    float eyex = 0.0f;
    float eyey = 3.0f;
    float eyez = 2.0f;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float fovy = 45.0;
    float aspect = 1.0;
    float zNear = 2.0;
    float zFar = 100.0;
    gluPerspective(fovy, aspect, zNear, zFar);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyex, eyey, eyez,
            0, 0, 0,
            0, 1, 0);
    
    glViewport(0, 0, 400, 400);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glColor3f(0, 0, 1);
}

void display1()
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

	mygllib::draw_xz_plane();
	mygllib::draw_axes();
	glutSwapBuffers();
}

void display2()
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

	mygllib::draw_xz_plane();
	mygllib::draw_axes();
	glutSwapBuffers();
}

void idle()
{
    mygllib::Camera & camera = *(mygllib::SingletonView::getInstance());
    //view.setCamera();
    camera.set_projection();
    camera.camlookat();
    //view.lookat();
    glutPostRedisplay();
}

int main(int argc, char ** argv)
{
	mygllib::init3d();	
	init1();
	glutDisplayFunc(display1);
    glutIdleFunc(idle);
	glutReshapeFunc(mygllib::Reshape::reshape);
	glutKeyboardFunc(mygllib::Keyboard::keyboard);
    //glutMouseFunc(mygllib::Mouse::mouse);
    //glutPassiveMotionFunc(mygllib::Mouse::passive_motion);
    //glutMotionFunc(mygllib::Mouse::motion);
    //glutEntryFunc(mygllib::Mouse::entry);

    /*
    glutInitWindowPosition(600, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Window 2");
    init2();
    glutDisplayFunc(display2);
    glutIdleFunc(idle);
    glutReshapeFunc(mygllib::Reshape::reshape);
    */

	glutMainLoop();

	return 0;
}
