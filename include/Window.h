#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/app/AppBasic.h"

using namespace ci;
using namespace ci::app;
using namespace std;

// Matt: Be sure to put some documentation in your header files
// so people reviewing your code know what is going on in here

class Window
{
	public:

		gl::Texture texture_;
		Vec2i pos_;
		
		Window(void);
		Window(Vec2i pos, gl::Texture texture);
		bool isInside(Vec2i pos);
		void draw();
};