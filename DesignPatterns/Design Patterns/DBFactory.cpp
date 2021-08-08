#include<iostream>

using namespace std;

class Database
{

public:
    virtual void getConnection() = 0;
};

class SqliteDB : public Database
{

public:
    void getConnection()
    {
        cout << "Get Connection for SqliteDB" << endl;
    }
};

class OracleDB : public Database
{

public:
    void getConnection()
    {
        cout << "Get Connection for OracleDB" << endl;
    }
};

class DBFactory
{
public:
    Database* createObj(string iStr)
    {
        if(iStr == "Sqlite")
            return new SqliteDB();

        else if(iStr == "Oracle")
            return new OracleDB();
    }
};

//int main()
//{
//    DBFactory* kFactoryObj = new DBFactory();
//    Database* kSqliteObj = kFactoryObj->createObj("Sqlite");
//    Database* kOracleObj = kFactoryObj->createObj("Oracle");
//
//    kSqliteObj->getConnection();
//    kOracleObj->getConnection();
//
//    return 0;
//
//}
