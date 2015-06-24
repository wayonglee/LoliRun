#ifndef _ENEMY_H_
#define _ENEMY_H_

#include"cocos2d.h"

class Enemy : public cocos2d::Sprite
{
public:
	bool empty;
	Enemy(void);
	~Enemy(void);
	CREATE_FUNC(Enemy);
	virtual bool init();
	void setImage();
	bool checkPlayerHit(cocos2d::Vec2 lolip);
};

#endif