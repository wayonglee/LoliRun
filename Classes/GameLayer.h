#ifndef _GAME_LAYER_H_
#define _GAME_LAYER_H_
#include"cocos2d.h"
class Player;
class Stage;
class GameLayer : public cocos2d::Layer
{
private:
	Player* loli;
	Stage* stage1,* stage2;
public:
	GameLayer();
	~GameLayer();
	CREATE_FUNC(GameLayer);
	virtual bool init();
	bool onTouchBegan(cocos2d::Touch*,cocos2d::Event*);
	void updateSelf(float);
};

#endif