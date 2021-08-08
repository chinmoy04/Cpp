#include <iostream>

using namespace std;

class VisualComponent
{
public:
    virtual void Draw() = 0;
};

class TextView : public VisualComponent
{
public:

    void Draw()
    {
        cout << "TextView Draw" << endl;
    }

};

class Decorator : public VisualComponent
{
public:
    VisualComponent *component;

    void Draw()
    {
        component->Draw();
    }
};

class ScrollDecorator: public Decorator
{
    int scrollPosition;

    public:
        ScrollDecorator(VisualComponent *_comp)
        {
            component = _comp;
        }
    void Draw()
    {
        Decorator::Draw();
        cout << "ScrollDecorator draw" << endl;
    }
};

class BorderDecorator: public Decorator
{
    int borderwidth;
public:
    BorderDecorator(VisualComponent *_comp)
    {
        component = _comp;
    }
    void Draw()
    {
        Decorator::Draw();
        cout << "BorderDecorator draw" << endl;
    }
};

int main()
{
    BorderDecorator *p = new BorderDecorator(new ScrollDecorator(new TextView()));
    p->Draw();

}
