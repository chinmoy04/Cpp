#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Observer
{
public:
    virtual void update()=0;
};


class Subject
{
    vector<class Observer*> obsVec;
public:
    void attach(Observer* obs)
    {
        obsVec.push_back(obs);
    }

    void detach()
    {
        obsVec.pop_back();
    }

    void notify()
    {
        for(unsigned int i = 0; i < obsVec.size(); i++)
        {
            obsVec[i]->update();
        }
    }

    virtual void setState(int i)=0;
    virtual int getState()=0;
};

class ConcreteSubject : public Subject
{
    int subjectState;
public:

    void setState(int i)
    {
        subjectState = i;
        Subject::notify();
    }

    int getState()
    {
        return subjectState;
    }
};


class ConcreteObserver : public Observer
{
    int observerState;
    Subject* pSubject;
public:
    ConcreteObserver(Subject* pSub)
    {
        pSubject = pSub;
    }

    void update()
    {
        observerState = pSubject->getState();
    }

    void getState()
    {
        cout << "ObserverState" << observerState << endl;
    }
};

int main5()
{
    Subject* sub1 = new ConcreteSubject();
    ConcreteObserver* obs1 = new ConcreteObserver(sub1);
    sub1->attach(obs1);

    sub1->setState(10);
    obs1->getState();

    sub1->setState(30);
    obs1->getState();

    getchar();

    return 0;
}
