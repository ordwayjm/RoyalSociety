#include "Window.h"

Window::Window(Vec2i pos, gl::Texture texture) 
{
	pos_ = pos;
	texture_ = texture;
}

Window::Window(void)
{
}

bool Window::isInside(Vec2i pos)
{
	return true;
}

void Window::draw()
{
	if(texture_)
		gl::draw(texture_, pos_);
	//gl::drawSolidRect(Rectf(pos_.x,pos_.y,pos_.x+width_,pos_.y+height_));
}