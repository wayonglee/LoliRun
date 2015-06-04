#ifndef _ENEMY_H_
#define _ENEMY_H_

#include"cocos2d.h"

class Enemy : public cocos2d::Sprite
{
public:
	Enemy(void);
	~Enemy(void);
	CREATE_FUNC(Enemy);
	virtual bool init();
};

#endif