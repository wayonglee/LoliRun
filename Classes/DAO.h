#ifndef _DAO_H_
#define _DAO_H_
#include"cocos2d.h"
class DAO
{
public:
	static int initDB();
	static int create(int score);
	static int remove(int id);
	static int modify(std::string pDate, std::string pContent);
	static cocos2d::ValueVector findAll();
	static cocos2d::ValueMap findById(std::string pDate);
};

#endif