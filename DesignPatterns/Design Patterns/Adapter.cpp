#include<iostream>
#include<vector>
#include<string>

using namespace std;

class TextView
{
public:
    int getExtent()
    {
        return 777;
    }
};


class Shapes
{
public:
    virtual void BoundingBox()=0;
    virtual void CreateManipulation()=0;
};

class Line : public Shapes
{
    TextView* ptext;
public:
    Line(TextView* text)
    {
        ptext = text;
    }

    void BoundingBox()
    {
        cout << ptext->getExtent() << endl;
    }

    void CreateManipulation()
    {
        cout << "Winter is coming" << endl;
    }
};

class TextShape : public Shapes
{
    TextView* ptext;
public:
    TextShape(TextView* text)
    {
        ptext = text;
    }

    void BoundingBox()
    {
        cout << ptext->getExtent() << "" << endl;
    }

    void CreateManipulation()
    {
        cout << "Winter is here" << endl;
    }
};


