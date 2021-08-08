#include<iostream>

using namespace std;


class AtmMachineState
{
public:

    virtual void insertCard()=0;

    virtual void ejectCard()=0;

    virtual void withDraw()=0;
};


class NoCardState : public AtmMachineState
{
public:

    void insertCard()
    {
        cout << "Card inserted" << endl;
    }

    void ejectCard()
    {
        cout << "Cant eject" << endl;
    }

    void withDraw()
    {
        cout << "Cant WithDraw" << endl;
    }
};



class HasCardState : public AtmMachineState
{
    void insertCard()
    {
        cout << "Cant insert Card" << endl;
    }

    void ejectCard()
    {
        cout << "Card ejected" << endl;
    }

    void withDraw()
    {
        cout << "Cash WithDrawn" << endl;
    }
};

class AtmMachine : public AtmMachineState
{
    AtmMachineState* _pState;

public:
    AtmMachine()
    {
        _pState = new NoCardState();
    }

    AtmMachineState* getState()
    {
        return _pState;
    }

    void setState(AtmMachineState* iState)
    {
        _pState = iState;
    }


    void insertCard()
    {
        _pState->insertCard();

        AtmMachineState* aState = new HasCardState();
        setState(aState);
    }

    void ejectCard()
    {
        _pState->ejectCard();

        AtmMachineState* aState = new NoCardState();
        setState(aState);
    }

    void withDraw()
    {
        _pState->withDraw();
    }
};



//int main()
//{
//    AtmMachine* atm = new AtmMachine();
//
//    atm->withDraw();
//    atm->ejectCard();
//    atm->insertCard();
//
//    atm->withDraw();
//    atm->insertCard();
//    atm->ejectCard();
//
//
//    return 0;
//}
