/*
 *	Justin Ordway
 *	CSE 274 A
 *	9/24/2012
 *
 *	HW02 - RoyalSociety
 *	Satisfies:
 *		A - Implements a Circular, Doubly-Linked List
 *		B - Controls are displayed by pressing the '?' key/button
 *		C - Items can be reordered using top buttons
 *		D - Items can be moved using WASD/Arrow Keys
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
	
	Node* sentinel_;
	
	gl::Texture winTexture_;
	
	Button* helpButton_;
	Button* newWinButton_;
	Button* reverseButton_;
	Button* leftButton_;
	Button* rightButton_;
	Button* deleteButton_;
	
	Vec2i mousePos_;
	
	bool leftClicked_;
	bool help_;
	int moveSpeed_;
};

void RoyalSocietyApp::setup()
{
	winTexture_ = loadImage("../resources/window.png");
	
	gl::Texture helpTexture = loadImage("../resources/help.png");
	gl::Texture newWinTexture = loadImage("../resources/newWindow.png");
	gl::Texture reverseTexture = loadImage("../resources/reverse.png");
	gl::Texture leftTexture = loadImage("../resources/left.png");
	gl::Texture rightTexture = loadImage("../resources/right.png");
	gl::Texture deleteTexture = loadImage("../resources/delete.png");

	helpButton_ = new Button(helpTexture, Vec2i(15, 15), 50, 50);
	newWinButton_ = new Button(newWinTexture, Vec2i(75, 15), 50, 50);
	reverseButton_ = new Button(reverseTexture, Vec2i(135, 15), 50, 50);
	leftButton_ = new Button(leftTexture, Vec2i(195, 15), 50, 50);
	rightButton_ = new Button(rightTexture, Vec2i(255, 15), 50, 50);
	deleteButton_ = new Button(deleteTexture, Vec2i(315, 15), 50, 50);

	sentinel_ = new Node();		// start cicular link list
	
	leftClicked_ = false;
	help_ = true;
	moveSpeed_ = 5;
}

/*
	Checks for mouse input/position from the user
*/
void RoyalSocietyApp::mouseDown(MouseEvent event)
{
	mousePos_ = event.getPos();
	leftClicked_ = event.isLeftDown();
}

/*
	Checks for keyboard input from the user, also moves currently selected window
*/
void RoyalSocietyApp::keyDown(KeyEvent event) {
	// Matt: Added usage of the '/' key, because it's simpler to press
	// one button than two!
	if(event.getChar() == '?' || event.getChar() == '/')
	{
		if(help_)
			help_ = false;
		else help_ = true;
	}
	if(sentinel_->next_ != sentinel_)
	{
		// check for key input and move window accordingly
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
		// check for button presses
		if(helpButton_->isInside(mousePos_))
		{
			if(help_)
				help_ = false;
			else help_ = true;
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

		/*
			Matt: For the left and right buttons, if there is only one window displayed,
			the window is (seemingly) deleted.  This is probably due to your sentinel not
			actually containing data.

			The lines I added in the following two if statements check to see if there is 
			only one other node besides the sentinel.  If this is the case (meaning both 
			the next_ and prev_ of the current node will be pointing to the sentinel, the 
			window will not (seemingly) delete itself when the moveToBack or moveToFront is called.
		*/
		if(leftButton_->isInside(mousePos_))
		{
			// Matt: Note addition of following line
			if(sentinel_->next_->prev_ != sentinel_ || sentinel_->next_->next_ != sentinel_)
				sentinel_->moveToBack(sentinel_->prev_);
		}
		if(rightButton_->isInside(mousePos_))
		{
			// Matt: Note addition of following line
			if(sentinel_->next_->prev_ != sentinel_ || sentinel_->next_->next_ != sentinel_)
				sentinel_->moveToFront(sentinel_->next_);
		}
		if(deleteButton_->isInside(mousePos_))
		{
			if(sentinel_ != sentinel_->next_)
				sentinel_->remove(sentinel_->next_);
		}
	}
}

void RoyalSocietyApp::draw()
{
	gl::clear(Color8u(0,0,0));		// clear screen on each update
	
	if (help_)
	{
		gl::drawString("Click the menu buttons to perform actions on the Linked List\n\nBUTTON COMMANDS (Left to Right):\nToggle Help Menu\nNew Window\nReverse List\nMove Backward in List\nMove Forward in List\nDelete Selected Window\n\nCONTROLS:\nW - Move Current Node Position Up\nS - Move Current Node Position Down\nA - Move Current Node Position Left\nD - Move Current Node Position Right\n? - Toggle Help Menu", Vec2i(15,70), Color8u(255,255,255), Font("Helvetica", 25));
	}

	// loop through each node
	Node* cur = sentinel_->prev_;
	while(cur != sentinel_)
	{
		cur->window_->draw();
		cur = cur->prev_;
	}
	
	// Matt: This is good that the buttons draw last so they always stay on top

	// draw buttons on top
	helpButton_->draw();
	newWinButton_->draw();
	reverseButton_->draw();
	leftButton_->draw();
	rightButton_->draw();
	deleteButton_->draw();
}

CINDER_APP_BASIC(RoyalSocietyApp, RendererGl)
