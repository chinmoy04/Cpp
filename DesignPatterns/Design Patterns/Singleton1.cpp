#include<iostream>

using namespace std;


class DBConnector
{
    DBConnector()
    {

    }

    static DBConnector* _pDBConnector;

public:

    static DBConnector* getInstance()
    {
        if(!_pDBConnector)
            _pDBConnector = new DBConnector();

        return _pDBConnector;
    }
};
