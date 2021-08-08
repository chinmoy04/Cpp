#include<iostream>

using namespace std;


class Hotel
{
public:

    virtual void getMenu()=0;
};


class VegRestaurent : public Hotel
{
public:

    void getMenu()
    {
        cout << "Veg Menu" << endl;
    }
};


class NonVegRestaurent : public Hotel
{
public:

    void getMenu()
    {
        cout << "Non-Veg Menu" << endl;
    }
};


class HotelKeeper
{
public:
    void getVegMenu()
    {
        VegRestaurent v;
        v.getMenu();
    }

    void getNonVegMenu()
    {
        NonVegRestaurent nv;
        nv.getMenu();
    }
};


//int main()
//{
//    HotelKeeper aHotelKeeper;
//
//    aHotelKeeper.getNonVegMenu();
//    aHotelKeeper.getVegMenu();
//
//    return 0;
//}
