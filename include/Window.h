#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Window
{
	public:

		int width_;
		int height_;
		Color8u color_;
		Vec2i pos_;
		
		bool move_;
		
		Window(void);
		Window(Vec2i pos, int width, int height, Color8u color);
		void update();
		void draw();
		bool isInside(Vec2i pos);
};