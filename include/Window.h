#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/app/AppBasic.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Window
{
	public:

		gl::Texture texture_;
		Vec2i pos_;
		
		Window(void);
		Window(Vec2i pos, gl::Texture texture);
		void update();
		void draw();
		bool isInside(Vec2i pos);
};