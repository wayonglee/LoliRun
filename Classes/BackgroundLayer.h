#ifndef _BACKGROUND_LAYER_H_
#define _BACKGROUND_LAYER_H_
#include"cocos2d.h"

class BackgroundLayer : public cocos2d::Layer
{
private:
	cocos2d::Vector<cocos2d::Sprite*> background;
public:
	BackgroundLayer(void);
	~BackgroundLayer(void);
	CREATE_FUNC(BackgroundLayer);
	virtual bool init();
	void addBackground();
	void updateSelf(float);
	void unRoll();
};

#endif