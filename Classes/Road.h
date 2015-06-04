#ifndef _ROAD_H_
#define _ROAD_H_

#include"cocos2d.h"

class Road : public cocos2d::Sprite
{
public:
	float platformTop;
	float platformButtom;
	float roadHeight;
	bool empty;
	Road(void);
	~Road(void);
	CREATE_FUNC(Road);
	virtual bool init();
	void setImage(int roadNumber,float spriteWidth,float spriteHeight);
	void setPlatform();
	bool checkPlayerLand(cocos2d::Vec2 lolip);
	bool checkPlayerAbove(cocos2d::Vec2 lolip);
	bool checkPlayerCrash(cocos2d::Vec2 lolip);
};

#endif