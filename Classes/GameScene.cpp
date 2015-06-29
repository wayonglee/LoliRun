#include"GameScene.h"
#include"GameLayer.h"
#include"BackgroundLayer.h"

USING_NS_CC;

GameScene::GameScene()
{

}

GameScene::~GameScene()
{

}

bool GameScene::init()
{
	if(!Scene::initWithPhysics())
	{
		return false;
	}
	auto backgroundLayer = BackgroundLayer::create();
	auto gameLayer = GameLayer::create();
	getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	addChild(backgroundLayer,0,0);
	addChild(gameLayer,1,1);

	return true;
}