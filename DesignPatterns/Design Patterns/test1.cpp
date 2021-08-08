#include<vector>

class Shape
{
public:
    virtual float area()=0;
};

class Polygon : public Shape
{
    float side1, side2, side3, side4;
public:
    float area();
};

class Grid
{
    std::vector<Polygon> polygonVec;
};

class Triangle : public Polygon
{
    float side1, side2, side3;
public:
    float area();
};

class Rectangle : public Polygon
{
    float length; float breadth;
public:
    float area();
};
