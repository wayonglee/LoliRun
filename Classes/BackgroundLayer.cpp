#include "BackgroundLayer.h"

USING_NS_CC;

BackgroundLayer::BackgroundLayer(void)
{
}


BackgroundLayer::~BackgroundLayer(void)
{
}

bool BackgroundLayer::init()
{
	if(!Layer::init())
	{
		return false;
	}
	addBackground();
	this->schedule(schedule_selector(BackgroundLayer::updateSelf),NULL);
	return true;
}

void BackgroundLayer::addBackground()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	background.pushBack(Sprite::create("back_1.png"));
	background.pushBack(Sprite::create("back_1.png"));
	background.at(0)->setAnchorPoint(Vec2(0,0));
	background.at(1)->setAnchorPoint(Vec2(0,0));
	background.at(0)->setPosition(0,visibleSize.height/3);
	background.at(1)->setPosition(background.at(1)->getContentSize().width,visibleSize.height/3);

	background.pushBack(Sprite::create("back_5.png"));
	background.pushBack(Sprite::create("back_5.png"));
	background.at(2)->setAnchorPoint(Vec2(0,0));
	background.at(3)->setAnchorPoint(Vec2(0,0));
	background.at(2)->setPosition(0,0);
	background.at(3)->setPosition(background.at(3)->getContentSize().width,0);

	addChild(background.at(0),0,1);
	addChild(background.at(1),0,2);
	addChild(background.at(2),1,3);
	addChild(background.at(3),1,4);

}

void BackgroundLayer::updateSelf(float)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	for(int i=0;i<2;i++)
	{
		background.at(i)->setPosition(background.at(i)->getPosition().x - 0.5,visibleSize.height/3);
		if(background.at(i)->getPosition().x == -background.at(i)->getContentSize().width)
		{
			background.at(i)->setPosition(background.at(i)->getContentSize().width,visibleSize.height/3);
		}
	}
	for(int i=2;i<4;i++)
	{
		background.at(i)->setPosition(background.at(i)->getPosition().x - 1.0, 0);
		if(background.at(i)->getPosition().x == -background.at(i)->getContentSize().width)
		{
			background.at(i)->setPosition(background.at(i)->getContentSize().width,0);
		}
	}
}