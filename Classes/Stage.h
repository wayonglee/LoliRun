#ifndef _STAGE_H_
#define _STAGE_H_

#include"cocos2d.h"

class Road;
class Enemy;
class Star;

class Stage : public cocos2d::Sprite
{
private:
	cocos2d::Vector<Road*> roads;
	cocos2d::Vector<Enemy*> enemies;
	cocos2d::Vector<Star*> stars;
	Road* emptyRoad;
	int size;
	int random;
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
	void addEnemy();
	void addStar();
	void addStage(cocos2d::Layer*,cocos2d::Vec2 position);
	bool checkPlayerAbove();
	bool checkPlayerCrash();
	bool checkPlayerHit();
	bool checkStarHit();
	void moveStage(float offset);
	void changeRandom(int max);
};

#endif