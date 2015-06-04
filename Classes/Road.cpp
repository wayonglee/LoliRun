#include "Road.h"

USING_NS_CC;

Road::Road(void)
{
}


Road::~Road(void)
{
}

bool Road::init()
{
	if(!Sprite::init())
	{
		return false;
	}
	empty = true;
	platformTop = 80.0f;
	platformButtom = 50.0f;
	return true;
}

void Road::setImage(int roadNumber,float spriteWidth,float spriteHeight)
{
	const char* roadName = String::createWithFormat("road_%d.png",roadNumber)->getCString();
	initWithFile(roadName,Rect(0,0,spriteWidth,spriteHeight));
	setAnchorPoint(Vec2(0.5,0));
	empty = false;
}



bool Road::checkPlayerLand(Vec2 lolip)
{
	if(this->getBoundingBox().containsPoint(lolip)&&lolip.y<platformTop+getPosition().y&&lolip.y>platformButtom+getPosition().y)
		return true;
	else return false;
}

bool Road::checkPlayerAbove(Vec2 lolip)
{
	if(this->getBoundingBox().containsPoint(lolip))
		return true;
	else return false;
}

bool Road::checkPlayerCrash(Vec2 lolip)
{
	if(this->getBoundingBox().containsPoint(Vec2(lolip.x+50,lolip.y))&&lolip.y<platformTop+getPosition().y)
		return true;
	else return false;
}