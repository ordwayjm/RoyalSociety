#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Node.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class RoyalSocietyApp : public AppBasic {
  public:
	
	Vec2i mousePos_;
	bool leftClicked_;

	void setup();
	void mouseDown(MouseEvent event);	
	void update();
	void draw();

  private:
	
	Node* sentinel_;			// starting empty node

};

void RoyalSocietyApp::setup()
{
	sentinel_ = new Node();		// start cicular link list
	leftClicked_ = false;
}

void RoyalSocietyApp::mouseDown( MouseEvent event )
{
	mousePos_ = event.getPos();
	leftClicked_ = true;
}

void RoyalSocietyApp::update()
{
	if(leftClicked_)
	{
		Window* newWindow = new Window(mousePos_, 400, 300, Color8u(255, 255, 255));
		sentinel_->insertAfter(new Node(), newWindow);
	}
}

void RoyalSocietyApp::draw()
{
	Node* cur = sentinel_->next_;
	while(cur != sentinel_) 
	{
		cur->window_->draw();
		cur = cur->next_;
	}
}

CINDER_APP_BASIC(RoyalSocietyApp, RendererGl)
