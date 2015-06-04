#ifndef  _PLAYER_H_
#define  _PLAYER_H_

#include"cocos2d.h"

enum PlayerState
{
	WALK,
	JUMP,
	JUMPDROP,
	DROP,
	DEAD
};

class Player : public cocos2d::Sprite
{
public:
	bool crash;
	Player(void);
	~Player(void);
	CREATE_FUNC(Player);
	virtual bool init();
	void addAnimate();
	void updateSelf(float);
	CC_SYNTHESIZE(float,runningSpeed,RunningSpeed);
	CC_SYNTHESIZE(PlayerState,curState,CurState);
	CC_SYNTHESIZE(bool,stateChangeable,StateChangeable);
	CC_SYNTHESIZE_RETAIN(cocos2d::Action*, walkAction, WalkAction);//Õ£¡Ù∂Øª≠
	CC_SYNTHESIZE_RETAIN(cocos2d::Action*, jumpAction, JumpAction);
	CC_SYNTHESIZE_RETAIN(cocos2d::JumpBy*, jumpBy, JumpBy);
	void changeState(PlayerState state);
	void jump();
	void jumpDrop(float);
	void jumpFinish(float);
	void drop();
	void dropFinish(float);
};

#endif