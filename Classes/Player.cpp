#include "Player.h"

USING_NS_CC;

Player::Player(void):
	walkAction(NULL),
	jumpAction(NULL),
	hurtAction(NULL),
	stateChangeable(true),
	runningSpeed(0.0f)
{
}


Player::~Player(void)
{
	CC_SAFE_RELEASE_NULL(walkAction);
	CC_SAFE_RELEASE_NULL(jumpAction);
	CC_SAFE_RELEASE_NULL(hurtAction);
}

bool Player::init()
{
	if(!Sprite::init())
	{
		return false;
	}
	initWithFile("s_1.png");
	addAnimate();
	setScale(0.5f);
	setAnchorPoint(Vec2(0.5f,0));
	changeState(WALK);
	crash = false;
	schedule(schedule_selector(Player::updateSelf),NULL);
	return true;
}

void Player::addAnimate()
{
	Vector<SpriteFrame*> pFrames;
	for(int i=0;i<6;i++)
	{
		const char* frameName = String::createWithFormat("s_%d.png",i+1)->getCString();
		SpriteFrame* pFrame = SpriteFrame::create(frameName,Rect(0,0,200,250));
		pFrames.pushBack(pFrame);
	}
	auto walkAnimation = Animation::createWithSpriteFrames(pFrames, 0.05);
	auto walkAnimate = Animate::create(walkAnimation);
	setWalkAction(RepeatForever::create(walkAnimate));

	pFrames.clear();
	pFrames.pushBack(SpriteFrame::create("s_jump.png",Rect(0,0,200,250)));

	auto jumpAnimation = Animation::createWithSpriteFrames(pFrames,0.1);
	auto jumpAnimate = Animate::create(jumpAnimation);
	setJumpAction(RepeatForever::create(jumpAnimate));

	pFrames.clear();
	pFrames.pushBack(SpriteFrame::create("s_hurt.png", Rect(0, 0, 200, 250)));

	auto hurtAnimation = Animation::createWithSpriteFrames(pFrames, 0.1);
	auto hurtAnimate = Animate::create(hurtAnimation);
	setHurtAction(RepeatForever::create(hurtAnimate));
}

void Player::updateSelf(float)
{
	if(crash)
	{
		setPosition(getPosition().x-runningSpeed,getPosition().y);
	}
	else if(getPosition().x<150&&curState==WALK)
	{
		setPosition(getPosition().x+1.5,getPosition().y);
	}
}

void Player::changeState(PlayerState state)
{
	if(stateChangeable || state==WALK || state==DEAD ||state==HURT)
	{
		switch(state)
		{
		case WALK:stopAllActions(); runAction(walkAction); break;
		case JUMP:stopAllActions(); runAction(JumpBy::create(1.5f,Vec2(0,-300),200,1));runAction(jumpAction);stateChangeable = false; jump();break;
		case DROP:runAction(MoveBy::create(2.0f,Vec2(0,-200))); break;
		case HURT: stopAllActions(); runAction(hurtAction); stateChangeable = false; break;
		case DEAD:stopAllActions(); stateChangeable = false; break;
		}
		curState = state;
	}
}

void Player::jump()
{
	this->scheduleOnce(schedule_selector(Player::jumpDrop),0.5f);
	//this->scheduleOnce(schedule_selector(Player::jumpFinish),3.5f);
}

void Player::jumpDrop(float)
{
	if (curState==JUMP)
		curState = JUMPDROP;
}

void Player::jumpFinish(float)
{
	if(curState==JUMPDROP)
	{
		stateChangeable = true;
		changeState(WALK);
	}
}