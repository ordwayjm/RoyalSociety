#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Node.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class RoyalSocietyApp : public AppBasic {
  public:

	void setup();
	void mouseDown(MouseEvent event);	
	void update();
	void draw();

  private:
	
	Node* sentinel_;			// starting empty node
	
	Vec2i mousePos_;
	bool leftClicked_;

	Window* window1;
	Window* window2;
};

void RoyalSocietyApp::setup()
{
	sentinel_ = new Node();		// start cicular link list
	leftClicked_ = false;

	window1 = new Window(Vec2i(50, 50), 400, 300, Color8u(255, 255, 0));
	window2 = new Window(Vec2i(100, 150), 150, 400, Color8u(0, 255, 255));

	sentinel_->insertAfter(sentinel_, window1);
	sentinel_->insertAfter(sentinel_, window2);
}

void RoyalSocietyApp::mouseDown( MouseEvent event )
{
	mousePos_ = event.getPos();
	leftClicked_ = true;
}

void RoyalSocietyApp::update()
{
	
}

void RoyalSocietyApp::draw()
{
	Node* cur = sentinel_->next_;
	while(cur != sentinel_)
	{
		cur->window_->draw();

		// go to next node in list
		cur = cur->next_;
	}
}

CINDER_APP_BASIC(RoyalSocietyApp, RendererGl)
