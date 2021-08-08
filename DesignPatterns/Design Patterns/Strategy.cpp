#include<iostream>

using namespace std;


class KickBehavior
{
public:

    virtual void kick()=0;
};

class LightningKick : public KickBehavior
{
public:

    void kick()
    {
        cout << "Lightning kick" << endl;
    }
};


class TornadoKick : public KickBehavior
{
public:

    void kick()
    {
        cout << "TornadoKick kick" << endl;
    }
};



class JumpBehavior
{
public:

    virtual void jump()=0;
};

class ShortJump : public JumpBehavior
{
public:

    void jump()
    {
        cout << "ShortJump" << endl;
    }
};


class LongJump : public JumpBehavior
{
public:

    void jump()
    {
        cout << "LongJump" << endl;
    }
};



class Fighter
{
    KickBehavior* _pKick;
    JumpBehavior* _pJump;

public:

    Fighter(KickBehavior* a, JumpBehavior* b)
    {
        _pKick = a;
        _pJump = b;
    }

    virtual void punch()=0;

    virtual void roll()=0;

    void kick()
    {
        _pKick->kick();
    }

    void jump()
    {
        _pJump->jump();
    }


};



class Ryu : public Fighter
{
public:
    Ryu(KickBehavior* a, JumpBehavior* b): Fighter(a, b){}

    void punch()
    {
        cout << "Ryu punch" << endl;
    }

    void roll()
    {
        cout << "Ryu Roll" << endl;
    }
};

class Ken : public Fighter
{
public:
    Ken(KickBehavior* a, JumpBehavior* b): Fighter(a, b){}

    void punch()
    {
        cout << "Ken punch" << endl;
    }

    void roll()
    {
        cout << "Ken Roll" << endl;
    }
};



//int main()
//{
//    JumpBehavior* j1 = new LongJump();
//    JumpBehavior* j2 = new ShortJump();
//
//    KickBehavior* k1 = new TornadoKick();
//    KickBehavior* k2 = new LightningKick();
//
//    Fighter* f1 = new Ryu(k1, j1);
//    Fighter* f2 = new Ken(k2, j2);
//
//    f1->kick();
//
//    f2->jump();
//
//
//    return 0;
//}
