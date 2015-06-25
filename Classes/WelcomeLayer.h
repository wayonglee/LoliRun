#ifndef _WELCOME_LAYER_H_
#define _WELCOME_LAYER_H_
#include"cocos2d.h"
class WelcomeLayer:public cocos2d::Layer
{
public:
	WelcomeLayer();
	~WelcomeLayer();
	CREATE_FUNC(WelcomeLayer);
	virtual bool init();
	void startGame(cocos2d::Object* pSender);
};

#endif