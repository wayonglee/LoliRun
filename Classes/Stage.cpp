#include "Stage.h"
#include "Player.h"

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
	setData(108.0f,126.0f,80.0f);
	addRoad();
	return true;
}

void Stage::setData(float sw,float sh,float ph)
{
	spriteWidth = sw;
	spriteHeight = sh;
	platformHeight = ph;
}

void Stage::addRoad()
{
	int a[] = {2,2,2,2,-1,-1,2,2,-1,2};
	emptyRoad = Sprite::create();
	emptyRoad->retain();
	for(int i=0;i<size;i++)
	{
		if(a[i]>0)
		{
			const char* roadName = String::createWithFormat("road_%d.png",a[i])->getCString();
			auto road = Sprite::create(roadName,Rect(0,0,spriteWidth,spriteHeight));
			road->setAnchorPoint(Vec2(0.5,0));
			roads.insert(i,road);
		}
		else roads.insert(i,emptyRoad);
	}
}

void Stage::addStage(Layer* layer,Vec2 pos)
{
	for(int i=0;i<size;i++)
	{
		if(roads.at(i)!=emptyRoad)
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
	/*if(loli->getCurState()==JUMP||loli->getCurState()==DROP)
	{
		for(int i=0;i<size;i++)
		{
			if(roads.at(i)!=emptyRoad)
				if(roads.at(i)->getBoundingBox().containsPoint(lolip)&&lolip.x<=platformHeight+startPos.y)
					loli->changeState(WALK);
		}
	}*/
	if(loli->getCurState()==WALK)
	{
		for(int i=0;i<size;i++)
		{
			if(roads.at(i)!=emptyRoad)
				if(roads.at(i)->getBoundingBox().containsPoint(lolip))
					return true;
		}
	}
	return false;
}

void Stage::moveStage(float offset)
{
	for(int i=0;i<size;i++)
	{
		if(roads.at(i)!=emptyRoad)
			roads.at(i)->setPosition(roads.at(i)->getPosition().x-offset,roads.at(i)->getPosition().y);
	}
	startPos.x -= offset;
	endPos.x -= offset;
}

void Stage::setPos(Vec2 pos)
{
	for(int i=0;i<size;i++)
	{
		if(roads.at(i)!=emptyRoad)
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