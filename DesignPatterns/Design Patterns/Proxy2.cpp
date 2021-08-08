#include<iostream>

using namespace std;


class Internet
{
public:

    virtual void connect()=0;

    virtual ~Internet()
    {
        cout << "base Dtor" << endl;
    }
};


class RealInternet : public Internet
{
public:
    RealInternet()
    {
        cout << "Ctor" << endl;
    }

    ~RealInternet()
    {
        cout << "Dtor" << endl;
    }

    void connect()
    {
        cout << "Connected" << endl;
    }
};


class ProxyInernet
{
    Internet* _pInternet;

public:
    ProxyInernet()
    {
        //if(_pInternet == NULL)
        _pInternet = new RealInternet();
    }

    ~ProxyInernet()
    {
        delete _pInternet;
    }

    void connect()
    {
        _pInternet->connect();
    }
};


//int main()
//{
//    ProxyInernet aInternet;
//
//    aInternet.connect();
//
//    return 0;
//}


