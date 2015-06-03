#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_
#include"cocos2d.h"

class GameScene : public cocos2d::Scene
{
public:
	GameScene();
	~GameScene();
	CREATE_FUNC(GameScene);
	virtual bool init();
};

#endif