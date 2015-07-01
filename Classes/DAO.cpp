#include "DAO.h"
#include "sqlite3.h"

USING_NS_CC;
using namespace std;

int DAO::initDB()
{
	auto sharedFileUtils = FileUtils::getInstance();
	string path = "ScoreList.sqlite3";
	bool isExist = false;
	sqlite3* db = NULL;

	if (sqlite3_open(path.c_str(), &db) != SQLITE_OK)
	{
		sqlite3_close(db);
		CCASSERT(false, "DB open failure.");
	}
	else
	{
		char* err;
		string createSQL = "CREATE TABLE IF NOT EXISTS Note(id INTEGER PRIMARY KEY,score INTEGER)";
		if (sqlite3_exec(db, createSQL.c_str(), NULL, NULL, &err) != SQLITE_OK)
		{
			sqlite3_close(db);
			CCASSERT(false, "Create table failure.");
		}
		sqlite3_close(db);
	}
	return 0;
}

int DAO::create(int score)
{
	initDB();
	sqlite3* db = NULL;
	string path = "ScoreList.sqlite3";
	if (sqlite3_open(path.c_str(), &db) != SQLITE_OK)
	{
		sqlite3_close(db);
		CCASSERT(false, "DB open failure.");
	}
	else
	{
		string sqlStr = "INSERT OR REPLACE INTO note(id,score) VALUES (null,?)";
		sqlite3_stmt* statement;
		if (sqlite3_prepare_v2(db, sqlStr.c_str(), -1, &statement, NULL) == SQLITE_OK)
		{
			string scoreString;
			ostringstream oss;
			oss << score;
			scoreString = oss.str();
			sqlite3_bind_text(statement, 1, scoreString.c_str(), -1, NULL);
			if (sqlite3_step(statement) != SQLITE_DONE)
			{
				CCASSERT(false, "Insert Data failure.");
			}
		}
		sqlite3_finalize(statement);
		sqlite3_close(db);
	}
	return 0;
}

int DAO::remove(int id)
{
	initDB();
	sqlite3* db = NULL;
	string path = "ScoreList.sqlite3";
	if (sqlite3_open(path.c_str(), &db) != SQLITE_OK)
	{
		sqlite3_close(db);
		CCASSERT(false, "DB open failure.");
	}
	else
	{
		string sqlStr = "DELETE from note where id = ?";
		sqlite3_stmt* statement;
		if (sqlite3_prepare_v2(db, sqlStr.c_str(), -1, &statement, NULL) == SQLITE_OK)
		{
			string idString;
			ostringstream oss;
			oss << id;
			idString = oss.str();
			sqlite3_bind_text(statement, 1, idString.c_str(), -1, NULL);
			if (sqlite3_step(statement) != SQLITE_DONE)
			{
				CCASSERT(false, "DELETE Data failure.");
			}
		}
		sqlite3_finalize(statement);
		sqlite3_close(db);
	}
	return 0;
}