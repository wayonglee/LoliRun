#ifndef _WELCOME_SCENE_H_
#define _WELCOME_SCENE_H_
#include"cocos2d.h"

class WelcomeLayer;

class WelcomeScene:public cocos2d::Scene
{
private:
	WelcomeLayer* welcomeLayer;
public:
	WelcomeScene();
	~WelcomeScene();
	CREATE_FUNC(WelcomeScene);
	virtual bool init();
};

#endif