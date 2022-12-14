 #include <iostream>
#include <GL/freeglut.h>
#include "Camera.h"
#include "Singleton.h"
#include "Keyboard.h"
#include "Light.h"

const float camSpeed = 0.05f;
void mygllib::Keyboard::keyboard(unsigned char key, int w, int h)
{
    mygllib::Camera & camera = *(mygllib::Singleton<mygllib::Camera>::getInstance());
	mygllib::Light & light = *(mygllib::Singleton<mygllib::Light>::getInstance());

    switch(key)
	{
		case 'w': camera.cameraPos += camSpeed * camera.cameraFront; break;
		case 's': camera.cameraPos -= camSpeed * camera.cameraFront; break;
		
		case 'a': 
		{
			camera.cameraPos -= glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * camSpeed; 
		}
		break;
		
		case 'd': 
		{
			camera.cameraPos += glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * camSpeed;
		}     		
		break;
		
		case 'v': camera.fovy() -= 0.1; break;
		case 'V': camera.fovy() += 0.1; break;
		case 'p': camera.aspect() -= 0.1; break;
		case 'P': camera.aspect() += 0.1; break;
		//case 'n': camera.zNear() -= 0.1; break;
		//case 'N': camera.zNear() += 0.1; break;
		//case 'f': camera.zFar() -= 0.1; break;
		//case 'F': camera.zFar() += 0.1; break;
		case '&':
			light.light_on(GL_LIGHT0);
			break;
		case '*':
			light.light_off(GL_LIGHT0);
			break;
	}
	light.set(GL_LIGHT0);
	camera.setCamera();
	camera.set_projection();
	camera.camlookat();	
	glutPostRedisplay();
}
