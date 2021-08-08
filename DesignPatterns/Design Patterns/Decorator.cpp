#include<iostream>

using namespace std;

class Widget1
{
public:

    virtual void draw()=0;
};


class TextField : public Widget1
{
public:

    void draw()
    {
        cout << "Text Field" << endl;
    }
};


class Decorator : public Widget1
{
    Widget1* _pWidget;
public:

    Decorator(Widget1* iWid)
    {
        _pWidget = iWid;
    }

    void draw()
    {
        _pWidget->draw();
    }
};


class BorderDecorator : public Decorator
{
public:

    BorderDecorator(Widget1* w) : Decorator(w){}

    void draw()
    {
        Decorator::draw();
        cout << "Border Decorator" << endl;
    }
};



class ScrollDecorator: public Decorator
{
  public:
    ScrollDecorator(Widget1 *w): Decorator(w){}

    void draw()
    {
        Decorator::draw();
        cout << "ScrollDecorator" << endl;
    }
};


//int main()
//{
//  Widget1 *aWidget = new BorderDecorator(new BorderDecorator(new ScrollDecorator
//    (new TextField())));
//
//  aWidget->draw();
//
//  return 0;
//}
