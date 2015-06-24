#ifndef _SCORE_LABEL_H_
#define _SCORE_LABEL_H_
#include"cocos2d.h"

class ScoreLabel:public cocos2d::LabelTTF
{
public:
	ScoreLabel();
	~ScoreLabel();
	CREATE_FUNC(ScoreLabel);
	virtual bool init();
	void setScore(int score);
};

#endif