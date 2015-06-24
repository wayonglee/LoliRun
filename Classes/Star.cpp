#include "Star.h"

USING_NS_CC;

Star::Star()
{
}


Star::~Star()
{
}

bool Star::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	empty = true;
	return true;
}

void Star::setImage(int h)
{
	initWithFile("star.png");
	setAnchorPoint(Vec2(0.5f, 0.5f));
	setScale(0.5);
	empty = false;
	height = h;
}

bool Star::checkStarHit(Vec2 lolip)
{
	auto pos = this->getPosition();
	if (pos.distance(Vec2(lolip.x,lolip.y+72.5)) <= 50)
	{
		return true;
	}
	return false;
}