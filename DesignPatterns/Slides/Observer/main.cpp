#include <iostream>

// Observer.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include <vector>
using namespace std;

class Observer
{
public:
	virtual void Update() = 0;
};


class Subject
{
private:
	vector<Observer *> o;
public:
	virtual void Attach(Observer *p)
	{
		o.push_back(p);
	}
	virtual void Detach(Observer *p)
	{
		// find and remove p
		o.erase(p);
	}
	void Notify()
	{
		for (auto x : o)
			x->Update();
	}

};

class SS_Modal : public Subject
{
private:
		int value;
public:
	int getValue() { return value; }
	void setValue(int val) { value = val; }

};

class SS_View1 : public Observer
{
private:
	SS_Modal *pSubject;
public:
	SS_View1(SS_Modal *p) { pSubject = p;  }
	void Update()
	{
		cout << "Update called for view-1" << endl;
		int val = pSubject->getValue();

	}

};

class SS_View2 : public Observer
{
private:
	SS_Modal *pSubject;
public:
	SS_View2(SS_Modal *p) { pSubject = p;  }
	void Update()
	{
		cout << "Update called for view-2" << endl;
		int val = pSubject->getValue();

	}

};


int main(int argc, char* argv[])
{
	SS_Modal ssmodal1;
	Observer *pview1 = new SS_View1(&ssmodal1);
    Observer *pview2 = new SS_View2(&ssmodal1);

	ssmodal1.Attach(pview1);
	ssmodal1.Attach(pview2);

	ssmodal1.Notify();

	delete pview1;
	delete pview2;

	return 0;
}


