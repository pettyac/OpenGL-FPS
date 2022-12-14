#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>
#include <GL/freeglut.h>

namespace mygllib
{
  class Light
  {
      public:
          Light():light_ambient{0, 0, 0, 1}, light_diffuse{1, 1, 1, 1},
                  light_specular{1, 1, 1, 1}, light_position{0, 0, 1, 0}
                  {}

          Light(float ambR, float ambG, float ambB, float ambA,
          float diffR, float diffG, float diffB, float diffA,
          float specR, float specG, float specB, float specA,
          float x, float y, float z, float w, float shininess)
          : light_ambient{ambR, ambG, ambB, ambA},
            light_diffuse{diffR, diffG, diffB, diffA},
            light_specular{specR, specG, specB, specA},
            light_position{x, y, z, w}
            {
  
            }

          void all_on();
          void all_off();
          void light_on(GLenum light);
          void light_off(GLenum light);
          void set(GLenum light);
          void set_position();

          bool on() { return on_; }
          float & x() { return light_position[0]; }
          float x() const { return light_position[0]; }
          
          float & y() { return light_position[1]; }
          float y() const { return light_position[1]; }
          
          float & z() { return light_position[2]; } 
          float z() const { return light_position[2]; }

        private:
  
            GLboolean on_;
            GLfloat light_ambient[4];
            GLfloat light_diffuse[4];
            GLfloat light_specular[4];
            GLfloat light_position[4];    
  };
}
#endif