#include <iostream>
#include "Material.h"
#include "gl3d.h"

float* mygllib::Material::ambient()
{
    return material + type_ * 13;
}

float* mygllib::Material::diffuse()
{
    return material + type_ * 13 + 4;
}

float* mygllib::Material::specular()
{
    return material + type_ * 13 + 8;
}

float* mygllib::Material::shininess()
{
    return material + type_ * 13 + 12;
}

void mygllib::Material::set()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient());
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse());
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular());
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess());
}