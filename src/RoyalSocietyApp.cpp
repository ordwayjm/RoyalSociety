/*
 *	Justin Ordway
 *	CSE 274 A
 *	9/24/2012
 *
 *	HW02 - RoyalSociety
 *	Satisfies:
 *		A - Implements a Circular, Doubly-Linked List
 *		B - Controls are displayed by pressing the '?' key
 *		C - Items can be reordered using the mouse
 *		E - Reverses the order of the list
 *
 */

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "Button.h"
#include "Node.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class RoyalSocietyApp : public AppBasic {
public:

	void setup();
	void mouseDown(MouseEvent event);	
	void keyDown(KeyEvent event);
	void update();
	void draw();

  private:
	
	Node* sentinel_;			// starting empty node
	
	gl::Texture winTexture_;
	Button* helpButton_;
	Button* newWinButton_;
	Button* reverseButton_;
	
	Vec2i mousePos_;
	bool leftClicked_;
	bool rightClicked_;

	int moveSpeed_;
};

void RoyalSocietyApp::setup()
{
	winTexture_ = loadImage("../resources/window.png");
	gl::Texture helpTexture = loadImage("../resources/help.png");
	gl::Texture newWinTexture = loadImage("../resources/newWindow.png");
	gl::Texture reverseTexture = loadImage("../resources/reverse.png");

	helpButton_ = new Button(helpTexture, Vec2i(15, 15), 50, 50);
	newWinButton_ = new Button(newWinTexture, Vec2i(75, 15), 50, 50);
	reverseButton_ = new Button(reverseTexture, Vec2i(135, 15), 50, 50);

	sentinel_ = new Node();		// start cicular link list
	leftClicked_ = false;
	rightClicked_ = false;

	moveSpeed_ = 5;
}

void RoyalSocietyApp::mouseDown(MouseEvent event)
{
	mousePos_ = event.getPos();
	rightClicked_ = event.isRightDown();
	leftClicked_ = event.isLeftDown();
}

void RoyalSocietyApp::keyDown(KeyEvent event) {
	if(sentinel_->next_ != sentinel_)
	{
		if(event.getCode() == KeyEvent::KEY_RIGHT || event.getChar() == 'd')
		{
			sentinel_->next_->window_->pos_.x += moveSpeed_;
		}
		else if(event.getCode() == KeyEvent::KEY_LEFT || event.getChar() == 'a')
		{
			sentinel_->next_->window_->pos_.x -= moveSpeed_;
		}
		else if(event.getCode() == KeyEvent::KEY_UP || event.getChar() == 'w')
		{
			sentinel_->next_->window_->pos_.y -= moveSpeed_;
		}
		else if(event.getCode() == KeyEvent::KEY_DOWN || event.getChar() == 's')
		{
			sentinel_->next_->window_->pos_.y += moveSpeed_;
		}
	}
}

void RoyalSocietyApp::update()
{
	if(leftClicked_)
	{
		leftClicked_ = false;
		if(helpButton_->isInside(mousePos_))
		{

		}
		if(newWinButton_->isInside(mousePos_))
		{
			Window* window = new Window(Vec2i(120, 100), winTexture_);
			sentinel_->insertBefore(sentinel_->next_, window); 
			window = 0;
		}
		if(reverseButton_->isInside(mousePos_))
		{
			sentinel_->reverse(sentinel_);
		}
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
	
	// draw buttons on top
	helpButton_->draw();
	newWinButton_->draw();
	reverseButton_->draw();
}

CINDER_APP_BASIC(RoyalSocietyApp, RendererGl)
