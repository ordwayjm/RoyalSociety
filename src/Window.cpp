#include "Window.h"

Window::Window(void)
{
}

Window::Window(Vec2i pos, gl::Texture texture) 
{
	pos_ = pos;
	texture_ = texture;
}

/*
	Checks if mouse position is currently inside the window
*/
bool Window::isInside(Vec2i pos)
{
	Rectf* rect = new Rectf(pos_.x, pos_.y, pos_.x + texture_.getWidth(), pos_.y + texture_.getHeight());
	return rect->contains(pos);
}

void Window::draw()
{
	if(texture_)
		gl::draw(texture_, pos_);
}