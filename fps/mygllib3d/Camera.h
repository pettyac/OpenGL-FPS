// File: View.h

#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "config.h"

namespace mygllib
{
	class ViewError
	{};

	//-------------------------------------------------------------------------
	// View class
	//
	// Each View object contains information on setting the eye/camera and
	// also the perspective projection (orthogonal projection is not included.)
	//
	// USAGE:
	// mygllib::View view;
	// view.eyex() = 10;
	// Sets x-coordinate of eye
	// view.lookat()
	// calls gluLookAt()
	// view.set_projection() // if type_ is PERSPECTIVE, calls gluPerspective
	//-------------------------------------------------------------------------
	class Camera
	{
	public:
		enum Projection
		{
			ORTHOGONAL, PERSPECTIVE
		};

		Camera(float eyex=0, float eyey=0.5, float eyez=3,
			float refx=0, float refy=0, float refz=0,
			float upx=0, float upy=1, float upz=0,
			Projection type=PERSPECTIVE,
			float fovy=90, float aspect=1, float zNear=0.1, float zFar=1000,
			float yaw = -90.0f, float pitch = 0, float speed = 2.5f)
			: cameraPos(glm::vec3(eyex, eyey, eyez)), 
			  cameraTarget(glm::vec3(refx, refy, refz)),
			  cameraUp(glm::vec3(upx, upy, upz)), type_(type),
			  fovy_(fovy), aspect_(aspect), zNear_(zNear), zFar_(zFar),
			  speed_(speed), yaw_(yaw), pitch_(pitch)
		{
			cameraDirection = glm::normalize(cameraPos - cameraTarget);
			cameraRight = glm::normalize(glm::cross(cameraUp, cameraDirection));
			cameraFront = glm::vec3(0, 0, -1);	
			worldUp = cameraUp;
		}

		float & eyex()				{ return eyex_; }
		float   eyex() const		{ return eyex_; }
		float & eyey() 				{ return eyey_; }
		float   eyey() const		{ return eyey_; }
		float & eyez()				{ return eyez_; }
		float   eyez() const		{ return eyez_; }
		void	eye(float x, float y, float z) { eyex_ = x; eyey_ = y;
												 eyez_ = z; }
		float & refx()				{ return refx_; }
		float   refx() const		{ return refx_; }
		float & refy()				{ return refy_; }
		float	refy() const		{ return refy_; }
		float & refz()				{ return refz_; }
		float	refz() const		{ return refz_; }
		void	ref(float x, float y, float z) { refx_ = x; refy_ = y;
												 refz_ = z; }
		float & upx()				{ return upx_; }
		float	upx() const			{ return upx_; }
		float & upy()				{ return upy_; }
		float	upy() const			{ return upy_; }
		float & upz()				{ return upz_; }
		float	upz() const			{ return upz_; }
		void    up(float x, float y, float z) { upx_ = x; upy_ = y; upz_ = z; }
		
		float & yaw()				{ return yaw_; }
		float 	yaw() const 		{ return yaw_; }
		float & pitch()				{ return pitch_; }
		float 	pitch() const		{ return pitch_; }
		float & fovy()				{ return fovy_; }
		float   fovy() const		{ return fovy_; }
		float & aspect()			{ return aspect_; }
		float   aspect() const		{ return aspect_; }
		float & zNear()				{ return zNear_; }
		float	zNear() const		{ return zNear_; }
		float & zFar()				{ return zFar_; }
		float  zFar() const			{ return zFar_; }
		Projection & type()			{ return type_; }
		Projection   type() const 	{ return type_; }

		void lookat() const
		{
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(eyex_, eyey_, eyez_,
						refx_, refy_, refz_,
						upx_, upy_, upz_);
		}

		void camlookat() const
		{
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(cameraPos.x, cameraPos.y, cameraPos.z,
				cameraTarget.x,cameraTarget.y,cameraTarget.z,
				cameraUp.x, cameraUp.y, cameraUp.z);
		}

		void set_projection() const
		{
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			switch (type_)
			{
				case PERSPECTIVE:
					if (zNear_ <= 0)
					{
						std::cout << "zNear is <= 0" << std::endl;
						throw ViewError();
					}
					if (zNear_ >= zFar_)
					{
						std::cout << "zNear is >= zFar" << std::endl;
						throw ViewError();
					}
					gluPerspective(fovy_, aspect_, zNear_, zFar_);
					break;
				case ORTHOGONAL:
					break;
			}
		}
		
		void reshape(int w, int h)
		{
			if (h == 0) h = 1;
			glViewport(0, 0, w, h);
		
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			aspect_ = double(w) / h;
			set_projection();
			glMatrixMode(GL_MODELVIEW);
		}
		
		void setCamera()
		{
			cameraFront.x = cos(glm::radians(yaw_)) * cos(glm::radians(pitch_));
			cameraFront.y = sin(glm::radians(pitch_));
			cameraFront.z = sin(glm::radians(yaw_)) * cos(glm::radians(pitch_));
			cameraFront = glm::normalize(cameraFront);

			cameraRight = glm::normalize(glm::cross(cameraFront, worldUp));
			cameraUp = glm::normalize(glm::cross(cameraRight, cameraFront));
			cameraTarget = cameraPos + cameraFront;
		}

		glm::vec3 cameraPos, cameraTarget, cameraDirection,
		cameraUp, cameraRight, cameraFront, worldUp;

	private:
		float eyex_, eyey_, eyez_;			 //coordinates of eye
		float refx_, refy_, refz_;			 //reference point of eye
		float upx_, upy_, upz_;				 //up vector of eye
		Projection type_;					 //ORTHOGONAL/PERSPECTIVE viewing
		float fovy_, aspect_, zNear_, zFar_; //Params for perspective view
		float speed_;
		float yaw_, pitch_, roll_;
	};

	inline
	std::ostream & operator<<(std::ostream & cout, const Camera & v)
	{
		cout << "<View "
			<< " eye:"
			<< '(' << v.eyex() << ',' << v.eyey() << ',' << v.eyez() << "),"
			<< " ref:"
			<< '(' << v.refx() << ',' << v.refy() << ',' << v.refy() << "),"
			<< " up:"
			<< '(' << v.upx() << ',' << v.upy() << ',' << v.upz() << "),"
			<< " perpective:";
		if (v.type() == 1)
		{
			cout << '(' << v.fovy() << ',' << v.aspect() << ',' << v.zNear()
				<< ',' << v.zFar() << ')';
		}
		cout << ">";
		return cout;
	}
}

extern mygllib::Camera camera;

#endif

