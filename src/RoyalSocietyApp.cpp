#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
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
	gl::Texture texture;
	
	Vec2i mousePos_;
	bool leftClicked_;
	bool rightClicked_;
};

void RoyalSocietyApp::setup()
{
	texture = loadImage("../resources/win95.png");
	sentinel_ = new Node();		// start cicular link list
	leftClicked_ = false;
	rightClicked_ = false;
}

void RoyalSocietyApp::mouseDown(MouseEvent event)
{
	mousePos_ = event.getPos();
	rightClicked_ = event.isRightDown();
	leftClicked_ = event.isLeftDown();
}

void RoyalSocietyApp::update()
{
	if(leftClicked_)
	{
		leftClicked_ = false;
		int r = rand()%255;
		int g = rand()%255;
		int b = rand()%255;
		Window* window = new Window(mousePos_, texture);
		sentinel_->insertBefore(sentinel_->next_, window); 
		window = 0;
	}
	else if(rightClicked_) 
	{
		rightClicked_ = false;
		sentinel_->reverse(sentinel_);	
	}
}

void RoyalSocietyApp::draw()
{
	gl::clear(Color8u(0,0,0));
	Node* cur = sentinel_->prev_;
	while(cur != sentinel_)
	{
		cur->window_->draw();
		cur = cur->prev_;
	}
}

CINDER_APP_BASIC(RoyalSocietyApp, RendererGl)
