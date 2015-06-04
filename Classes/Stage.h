#ifndef _STAGE_H_
#define _STAGE_H_

#include"cocos2d.h"

class Road;
class Enemy;

class Stage : public cocos2d::Sprite
{
private:
	cocos2d::Vector<Road*> roads;
	Road* emptyRoad;
	int size;
	float spriteWidth;
	float spriteHeight;
public:
	Stage(void);
	~Stage(void);
	CREATE_FUNC(Stage);
	CC_SYNTHESIZE(cocos2d::Vec2,startPos,StartPos);
	CC_SYNTHESIZE(cocos2d::Vec2,endPos,EndPos);
	virtual bool init();
	void setData(float sw,float sh);
	void addRoad();
	void addStage(cocos2d::Layer*,cocos2d::Vec2 position);
	bool checkPlayerAbove();
	bool checkPlayerCrash();
	void moveStage(float offset);
	void setPos(cocos2d::Vec2 position);
	void checkJump();
};

#endif