#include "ScoreLabel.h"
#include<sstream>

USING_NS_CC;
using namespace std;

ScoreLabel::ScoreLabel()
{
}


ScoreLabel::~ScoreLabel()
{
}

bool ScoreLabel::init()
{
	if (!LabelTTF::init())
	{
		return false;
	}
	this->setColor(Color3B::BLACK);
	this->setFontName("Arial");
	this->setFontSize(30);
	return true;
}

void ScoreLabel::setScore(int score)
{
	string scoreString;
	ostringstream oss;
	oss << score;
	scoreString = oss.str();
	this->setString("score:" + scoreString);
}