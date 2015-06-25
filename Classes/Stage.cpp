#include "Stage.h"
#include "Player.h"
#include "Road.h"
#include "Enemy.h"
#include "Star.h"
#include "json/rapidjson.h"
#include "json/document.h"

USING_NS_CC;
using namespace rapidjson;
using namespace std;

Stage::Stage(void)
{
}


Stage::~Stage(void)
{
}

bool Stage::init()
{
	if(!Sprite::init())
	{
		return false;
	}
	size = 15;
	setData(108.0f,126.0f);
	random = 5;
	return true;
}

void Stage::setData(float sw,float sh)
{
	spriteWidth = sw;
	spriteHeight = sh;
}

void Stage::addRoad()
{
	Document doc;//¶ÁÈ¡json
	string data = FileUtils::getInstance()->getStringFromFile("stage.json");
	doc.Parse<0>(data.c_str());
	rapidjson::Value &v = doc["stage"][random];
	for(int i=0;i<size;i++)
	{
		auto road = Road::create();
		if (v["roads"][i].GetInt()>0)
		{
			road->setImage(v["roads"][i].GetInt(), spriteWidth, spriteHeight);
		}
		roads.insert(i,road);
	}
}

void Stage::addEnemy()
{
	Document doc;//¶ÁÈ¡json
	string data = FileUtils::getInstance()->getStringFromFile("stage.json");
	doc.Parse<0>(data.c_str());
	rapidjson::Value &v = doc["stage"][random];
	for (int i = 0; i<size; i++)
	{
		auto enemy = Enemy::create();
		if (v["enemies"][i].GetInt()==1)
		{
			enemy->setImage();
		}
		enemies.insert(i,enemy);
	}
}

void Stage::addStar()
{
	Document doc;
	string data = FileUtils::getInstance()->getStringFromFile("stage.json");
	doc.Parse<0>(data.c_str());
	rapidjson::Value &v = doc["stage"][random];
	for (int i = 0; i<size; i++)
	{
		auto star = Star::create();
		if (v["stars"][i].GetInt() > 0)
		{
			star->setImage(v["stars"][i].GetInt());
		}
		stars.insert(i, star);
	}
}

void Stage::addStage(Layer* layer,Vec2 pos)
{
	changeRandom(2,7);
	roads.clear();
	enemies.clear();
	stars.clear();
	addRoad();
	addEnemy();
	addStar();
	Document doc;//¶ÁÈ¡json
	string data = FileUtils::getInstance()->getStringFromFile("stage.json");
	doc.Parse<0>(data.c_str());
	rapidjson::Value &v = doc["stage"][random];
	for(int i=0;i<size;i++)
	{
		int height = v["height"][i].GetInt();
		if(!roads.at(i)->empty)
		{
			roads.at(i)->setPosition(roads.at(i)->getContentSize().width / 2 + roads.at(i)->getContentSize().width*i + pos.x, pos.y + height);
			layer->addChild(roads.at(i));
			if (!enemies.at(i)->empty)
			{
				enemies.at(i)->setPosition(roads.at(i)->getContentSize().width / 2 + roads.at(i)->getContentSize().width*i + pos.x, pos.y + roads.at(i)->getContentSize().height - 50 + height);
				layer->addChild(enemies.at(i));
			}
			if (!stars.at(i)->empty)
			{
				stars.at(i)->setPosition(roads.at(i)->getContentSize().width / 2 + roads.at(i)->getContentSize().width*i + pos.x, pos.y + roads.at(i)->getContentSize().height + height + (stars.at(i)->height-1) * 40);
				layer->addChild(stars.at(i));
			}
		}
		else
		{
			if (!stars.at(i)->empty)
			{
				stars.at(i)->setPosition(roads.at(1)->getContentSize().width / 2 + roads.at(1)->getContentSize().width*i + pos.x, pos.y + roads.at(1)->getContentSize().height + height + (stars.at(i)->height - 1) * 40);
				layer->addChild(stars.at(i));
			}
		}
	}
	startPos = pos;
	endPos = Vec2(pos.x + spriteWidth * size,pos.y);
}

bool Stage::checkPlayerAbove()
{
	Player* loli = (Player*)Director::getInstance()->getRunningScene()->getChildByTag(1)->getChildByTag(1);
	Vec2 lolip = loli->getPosition();
	if(loli->getCurState()==JUMPDROP||loli->getCurState()==DROP)
	{
		for(int i=0;i<size;i++)
		{
			if(!roads.at(i)->empty)
				if(roads.at(i)->checkPlayerLand(lolip))
				{
					loli->setStateChangeable(true);
					loli->changeState(WALK);
					loli->setPosition(lolip.x, roads.at(i)->platformTop + roads.at(i)->getPosition().y);
					return true;
				}
		}
	}
	if(loli->getCurState()==WALK)
	{
		for(int i=0;i<size;i++)
		{
			if(!roads.at(i)->empty)
				if(roads.at(i)->checkPlayerAbove(lolip))
					return true;
		}
	}
	return false;
}

bool Stage::checkPlayerCrash()
{
	Player* loli = (Player*)Director::getInstance()->getRunningScene()->getChildByTag(1)->getChildByTag(1);
	Vec2 lolip = loli->getPosition();
	if (loli->getCurState() == WALK || loli->getCurState() == DROP || loli->getCurState() == JUMPDROP)
	{
		for(int i=0;i<size;i++)
		{
			if(!roads.at(i)->empty)
				if(roads.at(i)->checkPlayerCrash(lolip))
					return true;
		}
	}
	return false;
}

bool Stage::checkPlayerHit()
{
	Player* loli = (Player*)Director::getInstance()->getRunningScene()->getChildByTag(1)->getChildByTag(1);
	Vec2 lolip = loli->getPosition();
	for (int i = 0; i<size; i++)
	{
		if (!enemies.at(i)->empty)
			if (enemies.at(i)->checkPlayerHit(lolip))
				return true;
	}
	return false;
}

bool Stage::checkStarHit()
{
	Player* loli = (Player*)Director::getInstance()->getRunningScene()->getChildByTag(1)->getChildByTag(1);
	Vec2 lolip = loli->getPosition();
	for (int i = 0; i<size; i++)
	{
		if (!stars.at(i)->empty)
			if (stars.at(i)->checkStarHit(lolip))
			{
				stars.at(i)->empty = true;
				stars.at(i)->setVisible(false);
				return true;
			}
	}
	return false;
}

void Stage::moveStage(float offset)
{
	for(int i=0;i<size;i++)
	{
		if(!roads.at(i)->empty)
			roads.at(i)->setPosition(roads.at(i)->getPosition().x-offset,roads.at(i)->getPosition().y);
		if (!enemies.at(i)->empty)
			enemies.at(i)->setPosition(enemies.at(i)->getPosition().x - offset, enemies.at(i)->getPosition().y);
		if (!stars.at(i)->empty)
			stars.at(i)->setPosition(stars.at(i)->getPosition().x - offset, stars.at(i)->getPosition().y);
	}
	startPos.x -= offset;
	endPos.x -= offset;
}

void Stage::changeRandom(int min,int max)
{
	srand(time(NULL));
	random = RandomHelper::random_int(min, max);
}