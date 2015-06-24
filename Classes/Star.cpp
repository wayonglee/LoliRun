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

void Star::setImage()
{
	initWithFile("star.png");
	setAnchorPoint(Vec2(0.5f, 0.5f));
	setScale(0.5);
	empty = false;
}

bool Star::checkStarHit(Vec2 lolip)
{
	auto pos = this->getPosition();
	if (pos.distance(lolip) <= 50)
	{
		return true;
	}
	return false;
}