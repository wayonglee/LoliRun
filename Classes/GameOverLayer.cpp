#include "GameOverLayer.h"
#include "BackgroundLayer.h"

USING_NS_CC;

GameOverLayer::GameOverLayer()
{
}


GameOverLayer::~GameOverLayer()
{
}

bool GameOverLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visiblesize = Director::getInstance()->getVisibleSize();

	auto background = Sprite::create("gameover.png");
	background->setPosition(visiblesize.width / 2, visiblesize.height/2);
	this->addChild(background);

	auto back = MenuItemImage::create("continueA.png", "continueB.png", CC_CALLBACK_1(GameOverLayer::backToMenu,this));
	back->setPosition(visiblesize.width / 2, visiblesize.height / 3);
	auto backMenu = Menu::create(back, NULL);
	backMenu->setPosition(0, 0);
	this->addChild(backMenu);

	return true;
}

void GameOverLayer::backToMenu(Object* pSender)
{
	Director::getInstance()->popScene();
}

void GameOverLayer::stopGame()
{
	auto backgroundLayer = (BackgroundLayer*)this->getParent()->getChildByTag(0);
	backgroundLayer->unRoll();
}