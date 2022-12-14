//File: main.cpp
  
#include <iostream>
#include <GL/freeglut.h>
#include "Light.h"

namespace mygllib
{
    void Light::all_on()
    {
        glEnable(GL_LIGHTING);
    }

    void Light::all_off()
    {
        glDisable(GL_LIGHTING);
    }

    void Light::light_on(GLenum light = GL_LIGHT0)
    {
        glEnable(light);
    }

    void Light::light_off(GLenum light = GL_LIGHT0)
    {
        glDisable(light);
    }

    void Light::set(GLenum light = GL_LIGHT0)
    {
        glLightfv(light, GL_AMBIENT, light_ambient);
        glLightfv(light, GL_DIFFUSE, light_diffuse);
        glLightfv(light, GL_SPECULAR, light_specular);
        glLightfv(light, GL_POSITION, light_position);
    }
    
    void Light::set_position()
    {
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    }
}