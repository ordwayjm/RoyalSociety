#include "Button.h"

Button::Button(void)
{
}

Button::Button(gl::Texture texture, Vec2i pos, int width, int height)
{
	texture_ = texture;
	pos_ = pos;
	width_ = width;
	height_ = height;
}

bool Button::isInside(Vec2i pos)
{
	Rectf* rect = new Rectf(pos_.x, pos_.y, pos_.x + width_, pos_.y + height_);
	return rect->contains(pos);
}

void Button::draw()
{
	if(texture_)
		gl::draw(texture_, pos_);
}