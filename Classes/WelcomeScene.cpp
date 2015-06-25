#include "WelcomeScene.h"
#include "WelcomeLayer.h"

USING_NS_CC;

WelcomeScene::WelcomeScene()
{
}


WelcomeScene::~WelcomeScene()
{
}

bool WelcomeScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	welcomeLayer = WelcomeLayer::create();
	this->addChild(welcomeLayer);
	return true;
}