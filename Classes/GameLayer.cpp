#include"GameLayer.h"
#include"Player.h"
#include"Stage.h"

USING_NS_CC;

GameLayer::GameLayer()
{

}

GameLayer::~GameLayer()
{

}

bool GameLayer::init()
{
	if(!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto body = PhysicsBody::createEdgeBox(visibleSize,PHYSICSBODY_MATERIAL_DEFAULT,5.0f);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
	edgeNode->setPhysicsBody(body);
	//addChild(edgeNode);

	loli = Player::create();
	loli->setPosition(100.0f,80.0f);
	addChild(loli,1,1);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);

	/*auto road = Sprite::create("road_1.png");
	auto material = PhysicsMaterial::PhysicsMaterial(100.0f,0.0f,0.0f);
	auto roadBody = PhysicsBody::createBox(road->getContentSize(),material);
	roadBody->setMass(PHYSICS_INFINITY);
	roadBody->setGravityEnable(false);
	road->setPhysicsBody(roadBody);
	road->setAnchorPoint(Vec2(0,0));
	road->setPosition(visibleSize.width/2,road->getContentSize().height/2);
	addChild(road);*/

	stage1 = Stage::create();
	stage2 = Stage::create();
	stage1->retain();
	stage2->retain();
	stage1->addStage(this,Vec2(0,0));
	stage2->addStage(this,Vec2(stage1->getEndPos().x,0));
	this->schedule(schedule_selector(GameLayer::updateSelf));
	return true;
}

bool GameLayer::onTouchBegan(Touch* pTouch,Event* pEvent)
{
	loli->changeState(JUMP);
	return true;
}

void GameLayer::updateSelf(float)
{
	if(loli->getCurState()!=DEAD)
	{
		stage1->moveStage(5.0f);
		stage2->moveStage(5.0f);
		if(stage1->getEndPos().x<0)
			stage1->setPos(Vec2(stage2->getEndPos().x,0));
		if(stage2->getEndPos().x<0)
			stage2->setPos(Vec2(stage1->getEndPos().x,0));
		if(!stage1->checkPlayerAbove()&&!stage2->checkPlayerAbove())
			loli->changeState(DROP);
	}
}