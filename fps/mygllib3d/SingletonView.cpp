//File: SingletonView.cpp
//Author: Adam Petty

#include "SingletonView.h"

mygllib::Camera * mygllib::SingletonView::instance_(new mygllib::Camera());

mygllib::Camera * mygllib::SingletonView::getInstance()
{
	return instance_;
}
