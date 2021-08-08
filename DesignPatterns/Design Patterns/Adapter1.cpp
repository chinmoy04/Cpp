#include<iostream>

using namespace std;

class Bird
{
public:
    virtual void fly()=0;
    virtual void makeSound()=0;
};

class Sparrow : public Bird
{
public:

    void fly()
    {
        cout << "fly" << endl;
    }

    void makeSound()
    {
        cout << "Chirp" << endl;
    }
};


class Duck
{
public:

    virtual void quack()=0;
};

class RedDuck : public Duck
{
public:

    void quack()
    {
        cout << "quack" << endl;
    }
};


class BirdAdapter : public Duck
{
    Bird* _pBird;

public:

    BirdAdapter(Bird* iBird)
    {
        _pBird = iBird;
    }

    void quack()
    {
        _pBird->makeSound();
    }
};


//int main()
//{
//    Sparrow* aSparrow = new Sparrow();
//    RedDuck* aRedDuck = new RedDuck();
//
//    Duck* aDuck = new BirdAdapter(aSparrow);
//
//    aDuck->quack();
//    aRedDuck->quack();
//    aSparrow->makeSound();
//
//    return 0;
//
//}
