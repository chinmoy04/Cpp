#include<iostream>
#include<string>

using namespace std;

class HousePlan
{
public:
    virtual void setBasement(const string& iBasement)=0;
    virtual void setRoof(const string& iRoof)=0;
    virtual void setWall(const string& iWall)=0;
    virtual void setStructure(const string& iStructure)=0;
};


class House : public HousePlan
{
    string aBasement;
    string aRoof;
    string aWall;
    string aStructure;

public:

    void setBasement(const string& iBasement)
    {
        aBasement = iBasement;
    }

    const string& getBasement()
    {
        return aBasement;
    }

    void setRoof(const string& iRoof)
    {
        aRoof = iRoof;
    }

    void setWall(const string& iWall)
    {
        aWall = iWall;
    }

    void setStructure(const string& iStructure)
    {
        aStructure = iStructure;
    }
};


class HouseBuilder
{
public:

    virtual void buildBasement()=0;

    virtual void buildRoof()=0;

    virtual void buildWall()=0;

    virtual void buildStructure()=0;

    virtual House getHouse()=0;

};


class IglooHouseBuilder : public HouseBuilder
{
    House* aHouse;
public:

    IglooHouseBuilder()
    {
        aHouse = new House();
    }

    ~IglooHouseBuilder()
    {
        delete aHouse;
    }

    void buildBasement()
    {
        aHouse->setBasement("Ice Bars");
    }

    void buildStructure()
    {
        aHouse->setStructure("Ice Blocks");
    }

    void buildWall()
    {
        aHouse->setWall("Ice Carvings");
    }

    void buildRoof()
    {
        aHouse->setRoof("Ice Dome");
    }

    House getHouse()
    {
        return *aHouse;
    }
};


class TipiHouseBuilder  : public HouseBuilder
{
    House* aHouse;
public:

    TipiHouseBuilder ()
    {
        aHouse = new House();
    }

    ~TipiHouseBuilder()
    {
        delete aHouse;
    }

    void buildBasement()
    {
        aHouse->setBasement("Wooden Poles");
    }

    void buildStructure()
    {
        aHouse->setStructure("Wood and Ice");
    }

    void buildWall()
    {
        aHouse->setWall("Fire Wood");
    }

    void bulidRoof()
    {
        aHouse->setRoof("Wood");
    }

    House getHouse()
    {
        return *aHouse;
    }
};


class CivilEngineer
{

    HouseBuilder* houseBuilder;

public:

    CivilEngineer(HouseBuilder* ihouseBuilder)
    {
        houseBuilder = ihouseBuilder;
    }

    House getHouse()
    {
        return houseBuilder->getHouse();
    }

    void constructHouse()
    {
        houseBuilder->buildBasement();
        houseBuilder->buildStructure();
        houseBuilder->buildRoof();
        houseBuilder->buildWall();
    }
};


//int main()
//{
//        HouseBuilder* iglooBuilder = new IglooHouseBuilder();
//        CivilEngineer* engineer = new CivilEngineer(iglooBuilder);
//
//        engineer->constructHouse();
//
//        House house = engineer->getHouse();
//
//        //System.out.println("Builder constructed: "+ house);
//        cout << "Builder Constructed:" << house.getBasement();
//
//        return 0;
//}
