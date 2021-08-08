#include <iostream>
#include <vector>

using namespace std;

class TextView
{
public:
    int GetExtent ()
    {
        cout << "TextView GetExtent called" << endl;
        return 1;
    }
};

class Shape
{
public:

    virtual int BoundingBox()=0;
    virtual int CreateManipulator()=0;
};

class Line : public Shape
{
    int BoundingBox()
    {
        cout << "Line BoundingBox" << endl;
        return 0;
    }

    int CreateManipulator() { }
};

class TextShape: public Shape
{
public:
    TextView tv;

    int BoundingBox()
    {
        cout << "Bounding Box of TextShape" << endl;
        int retval = tv.GetExtent();
        return retval;
    }

    int CreateManipulator()
    {
        // add manipulation functionality
        return 1;
    }
};


class DrawingEditor
{
    vector<Shape *> vShapes;
    public:
    void Add(Shape *s)
    {
        vShapes.push_back(s);
    }

    void Draw()
    {
		for (auto x : vShapes)
			x->BoundingBox();
    }
};


main()
{
    DrawingEditor de;

    Shape *ps1 = new Line();
    Shape *ps2 = new TextShape();

    de.Add(ps1);
    de.Add(ps2);

    de.Draw();

    delete ps1;
    delete ps2;

}
