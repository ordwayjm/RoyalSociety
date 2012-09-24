#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/app/AppBasic.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Button
{
	public:

		Vec2i pos_;
		
		int width_;
		int height_;

		gl::Texture texture_;
		
		Button(void);
		Button(gl::Texture texture, Vec2i pos, int width, int height);
		bool isInside(Vec2i pos);
		void draw();
};

