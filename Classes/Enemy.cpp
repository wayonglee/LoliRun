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

	return true;
}