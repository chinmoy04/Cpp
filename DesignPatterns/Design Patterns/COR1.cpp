#include<iostream>

using namespace std;

class Chain
{
public:

    virtual void setNextChain(Chain* iChain)=0;
    virtual void process(int input)=0;
};


class NegProcessor : public Chain
{
    Chain* _pChain;

public:

    void setNextChain(Chain* iChain)
    {
        _pChain = iChain;
    }

    void process(int input)
    {
        if(input < 0)
        {
            cout << "-ve number" << endl;
        }
        else
        {
            _pChain->process(input);
        }
    }
};


class NullProcessor : public Chain
{
    Chain* _pChain;

public:

    void setNextChain(Chain* iChain)
    {
        _pChain = iChain;
    }

    void process(int input)
    {
        if(input == 0)
        {
            cout << "Null value" << endl;
        }
        else
        {
            _pChain->process(input);
        }
    }
};

class PosProcessor : public Chain
{
    Chain* _pChain;

public:

    void setNextChain(Chain* iChain)
    {
        _pChain = iChain;
    }

    void process(int input)
    {
        if(input > 0)
        {
            cout << "+ve number" << endl;
        }
        else
        {
            _pChain->process(input);
        }
    }
};


//int main()
//{
//    Chain* c1 = new NegProcessor();
//    Chain* c2 = new NullProcessor();
//    Chain* c3 = new PosProcessor();
//
//    c1->setNextChain(c2);
//    c2->setNextChain(c3);
//
//    c1->process(-1);
//    c1->process(0);
//    c1->process(21);
//
//    return 0;
//
//}
