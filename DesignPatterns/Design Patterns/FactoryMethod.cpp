#include<iostream>

using namespace std;

class TwoWheeler;
class ThreeWheeler;
class FourWheeler;

class Vehicle
{
public:
    virtual void getDescription() = 0;
    static Vehicle* create(const string& vehicleType);
};

class TwoWheeler : public Vehicle
{
public:
    void getDescription()
    {
        cout << "Two Wheeler" << endl;
    }
};


class ThreeWheeler : public Vehicle
{
public:
    void getDescription()
    {
        cout << "Three Wheeler" << endl;
    }
};


class FourWheeler : public Vehicle
{
public:
    void getDescription()
    {
        cout << "Four Wheeler" << endl;
    }
};

Vehicle* Vehicle::create(const string& vehicleType)
{
        if(vehicleType == "TwoWheeler")
            return new TwoWheeler();
        else if(vehicleType == "ThreeWheeler")
            return new ThreeWheeler();
        else if(vehicleType == "FourWheeler")
            return new FourWheeler();
        else
            return NULL;
}


class Client
{
    Vehicle* _pVehicle;
public:
    Client(const string& type)
    {
        _pVehicle = Vehicle::create(type);
    }

    ~Client()
    {
        delete _pVehicle;
        _pVehicle = NULL;
    }

    Vehicle* getVehicle()
    {
        return _pVehicle;
    }
};


//// Driver program
//int main() {
//    Client *pClient = new Client("ThreeWheeler");
//    Vehicle * pVehicle = pClient->getVehicle();
//    pVehicle->getDescription();
//    return 0;
//}
