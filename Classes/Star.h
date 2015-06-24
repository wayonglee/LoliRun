#ifndef _STAR_H_
#define _STAR_H_
#include"cocos2d.h"

class Star:public cocos2d::Sprite
{
public:
	bool empty;
	int height;
	Star();
	~Star();
	CREATE_FUNC(Star);
	virtual bool init();
	void setImage(int h);
	bool checkStarHit(cocos2d::Vec2 lolip);
};
#endif