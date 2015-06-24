#include "Enemy.h"

USING_NS_CC;

Enemy::Enemy(void)
{
}


Enemy::~Enemy(void)
{
}

bool Enemy::init()
{
	if(!Sprite::init())
	{
		return false;
	}
	empty = true;
	return true;
}

void Enemy::setImage()
{
	initWithFile("enemy.png");
	setAnchorPoint(Vec2(0.5f,0));
	setScale(0.5);
	empty = false;
}

bool Enemy::checkPlayerHit(Vec2 lolip)
{
	auto pos = this->getPosition();
	if (lolip.y>=pos.y&&pos.distance(lolip)<=50)
	{
		return true;
	}
	return false;
}