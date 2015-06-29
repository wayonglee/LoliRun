#ifndef _GAME_OVER_LAYER_H_
#define _GAME_OVER_LAYER_H_

#include"cocos2d.h"

class GameOverLayer:public cocos2d::Layer
{
public:
	GameOverLayer();
	~GameOverLayer();
	CREATE_FUNC(GameOverLayer);
	virtual bool init();
	void backToMenu(cocos2d::Object* pSender);
	void stopGame();
};

#endif