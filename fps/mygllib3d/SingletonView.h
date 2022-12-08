//File: SingletonView.h
//Author: Adam Petty

#ifndef SINGLETONVIEW_H
#define SINGLETONVIEW_H

#include "Camera.h"

namespace mygllib
{
	class SingletonView
	{
	public:
		static mygllib::Camera * getInstance();
	private:
		static Camera * instance_;
	};
}

#endif
