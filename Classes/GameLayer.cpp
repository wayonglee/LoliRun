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

	runningSpeed = 5.0f;

	loli = Player::create();
	loli->setPosition(150.0f,80.0f);
	loli->setRunningSpeed(5.0f);
	addChild(loli,10,1);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);

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
	if (loli->getCurState() != DEAD&&loli->getCurState() != HURT)
	{
		stage1->moveStage(5.0f);
		stage2->moveStage(5.0f);
		if(stage1->getEndPos().x<0)
			stage1->addStage(this,Vec2(stage2->getEndPos().x,0));
		if(stage2->getEndPos().x<0)
			stage2->addStage(this,Vec2(stage1->getEndPos().x,0));//ÒÆ¶¯¹Ø¿¨
		if(!stage1->checkPlayerAbove()&&!stage2->checkPlayerAbove())
			loli->changeState(DROP);
		if (stage1->checkPlayerHit() || stage2->checkPlayerHit())
			loli->changeState(HURT);
		if(stage1->checkPlayerCrash()||stage2->checkPlayerCrash())
			loli->crash = true;
		else loli->crash = false;
		if (loli->getPosition().y <= -loli->getContentSize().height*loli->getScale() || loli->getPosition().x <= -loli->getContentSize().width*loli->getScale())
			loli->changeState(DEAD);
		stage1->checkStarHit();
		stage2->checkStarHit();
	}
}