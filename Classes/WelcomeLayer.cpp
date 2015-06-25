#include "WelcomeLayer.h"
#include "GameScene.h"

USING_NS_CC;

WelcomeLayer::WelcomeLayer()
{
}


WelcomeLayer::~WelcomeLayer()
{
}

bool WelcomeLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Sprite* background = Sprite::create("MainMenu.png");
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(background);
	MenuItemImage* startButton = MenuItemImage::create("newgameA.png", "newgameB.png", CC_CALLBACK_1(WelcomeLayer::startGame,this));
	startButton->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	MenuItemImage* aboutButton = MenuItemImage::create("aboutA.png", "aboutB.png");
	aboutButton->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 100);
	Menu* mainMenu = Menu::create(startButton, aboutButton,NULL);
	mainMenu->setPosition(0, 0);
	this->addChild(mainMenu,1);
	return true;
}

void WelcomeLayer::startGame(Object* pSender)
{
	GameScene* scene = GameScene::create();
	Director::getInstance()->pushScene(scene);
}