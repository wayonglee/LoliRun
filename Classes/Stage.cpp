#include "Stage.h"
#include "Player.h"
#include "Road.h"
#include "Enemy.h"

USING_NS_CC;

Stage::Stage(void)
{
}


Stage::~Stage(void)
{

}

bool Stage::init()
{
	if(!Sprite::init())
	{
		return false;
	}
	size = 10;
	setData(108.0f,126.0f);
	addRoad();
	return true;
}

void Stage::setData(float sw,float sh)
{
	spriteWidth = sw;
	spriteHeight = sh;
}

void Stage::addRoad()
{
	int a[] = {2,2,2,2,-1,-1,2,2,2,2};
	for(int i=0;i<size;i++)
	{
		auto road = Road::create();
		if(a[i]>0)
		{
			road->setImage(a[i],spriteWidth,spriteHeight);
		}
		roads.insert(i,road);
	}
}

void Stage::addStage(Layer* layer,Vec2 pos)
{
	for(int i=0;i<size;i++)
	{
		if(!roads.at(i)->empty)
		{
			roads.at(i)->setPosition(roads.at(i)->getContentSize().width/2+roads.at(i)->getContentSize().width*i+pos.x,pos.y);
			layer->addChild(roads.at(i));
		}
	}
	startPos = pos;
	endPos = Vec2(pos.x + spriteWidth * size,pos.y);
}

bool Stage::checkPlayerAbove()
{
	Player* loli = (Player*)Director::getInstance()->getRunningScene()->getChildByTag(1)->getChildByTag(1);
	Vec2 lolip = loli->getPosition();
	if(loli->getCurState()==JUMPDROP||loli->getCurState()==DROP)
	{
		for(int i=0;i<size;i++)
		{
			if(!roads.at(i)->empty)
				if(roads.at(i)->checkPlayerLand(lolip))
				{
					loli->setStateChangeable(true);
					loli->changeState(WALK);
					loli->setPosition(lolip.x,roads.at(i)->platformTop+startPos.y);
					return true;
				}
		}
	}
	if(loli->getCurState()==WALK)
	{
		for(int i=0;i<size;i++)
		{
			if(!roads.at(i)->empty)
				if(roads.at(i)->checkPlayerAbove(lolip))
					return true;
		}
	}
	return false;
}

bool Stage::checkPlayerCrash()
{
	Player* loli = (Player*)Director::getInstance()->getRunningScene()->getChildByTag(1)->getChildByTag(1);
	Vec2 lolip = loli->getPosition();
	if(loli->getCurState()==WALK)
	{
		for(int i=0;i<size;i++)
		{
			if(!roads.at(i)->empty)
				if(roads.at(i)->checkPlayerCrash(lolip))
					return true;
		}
	}
	return false;
}

void Stage::moveStage(float offset)
{
	for(int i=0;i<size;i++)
	{
		if(!roads.at(i)->empty)
			roads.at(i)->setPosition(roads.at(i)->getPosition().x-offset,roads.at(i)->getPosition().y);
	}
	startPos.x -= offset;
	endPos.x -= offset;
}

void Stage::setPos(Vec2 pos)
{
	for(int i=0;i<size;i++)
	{
		if(!roads.at(i)->empty)
		{
			roads.at(i)->setPosition(roads.at(i)->getContentSize().width/2+roads.at(i)->getContentSize().width*i+pos.x,pos.y);
		}
	}
	startPos = pos;
	endPos = Vec2(pos.x + spriteWidth * size,pos.y);
}

void Stage::checkJump()
{
	
}