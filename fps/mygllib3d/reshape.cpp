// File: reshape.cpp
// Author: Adam Petty

#include "Camera.h"
#include "SingletonView.h"
#include "reshape.h"

void mygllib::Reshape::reshape(int w, int h)
{
	if (h == 0) h = 1;
	glViewport(0, 0, w, h);
	mygllib::Camera * pcamera = mygllib::SingletonView::getInstance();
	pcamera->aspect() = double(w) / h;
	pcamera->set_projection();
	pcamera->lookat();
}
