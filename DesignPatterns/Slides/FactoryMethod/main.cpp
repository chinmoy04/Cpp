#include <iostream>

using namespace std;

// FactoryMethod.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "CreatorSimple.h"
#include <vector>
using namespace std;
class Document
{
	virtual void Open() = 0;
	virtual void Close() = 0;
};
class Application
{
	virtual void CreateDocument() = 0;
	vector<Document *> docs;

};



using namespace std;

// the creator class uses parametrized factory method
void UsingFactoryMethod()
{
	int prod_option;
	Creator *pCreator;
	Product *pProd= NULL;


	pCreator = new CreatorSimple();

	while (1)
	{
		cout << "Enter 1 for Product A or Enter 2 for Product B, any other to exit" << endl;
		cin >> prod_option;
		if (prod_option == 1)
		{
			pProd = pCreator->Create(PRODUCT_A);
		}
		else
			if (prod_option == 2)
			{
				pProd = pCreator->Create(PRODUCT_B);
			}
			else
			{
				cout << "breaking out" << endl;
				break;
			}
		cout << pProd->GetName() << endl;
		delete pProd; // not using anymore, so deleting it,
					  // one could store it in a vector for later retrieval and deletion
	}
	delete pCreator;
}

// it needs to know the exact implementation details ProductA, ProductB
// tomorrow ProductA is changed to MagicProduct; we will need to modify it here
// a new product gets added, framework needs to include it
// Another thange that productA is productB & product B is productA - the change will just be
// in creator

#include "ProductA.h"
#include "ProductB.h"

	void WithoutUsingFactoryMethod()
	{
		int prod_option;
		Product *pProd;

		while (1)
		{
			cout << "Enter 1 for Product A or Enter 2 for Product B, any other to exit" << endl;
			cin >> prod_option;
			if (prod_option == 1)
			{
				pProd = new ProductA();
			}
			else
				if (prod_option == 2)
				{
					pProd = new ProductB();
				}
				else
				{
					cout << "breaking out" << endl;
					break;
				}
			cout << pProd->GetName() << endl;
			delete pProd;
		}
	}

int main(int argc, char *argv[])
{
	UsingFactoryMethod();
	cout << "Now without using Factory Method" << endl;
	WithoutUsingFactoryMethod();

	return 0;
}

class Room
{
public:
	virtual const char *getname() = 0;
};

class BasicRoom : public Room
{
public:
	virtual const char *getname()
	{
		return "basic room";
	}
};

class SpecialRoom : public Room
{
public:
	virtual const char *getname()
	{
		return "special room";
	}
};


class Maze
{
public:
	virtual Room* CreateRoom() = 0;
};

class BasicMaze : public Maze
{
public:
	Room *CreateRoom()
	{
		return new BasicRoom();
	}
};

class SpecialMaze : public Maze
{
	Room *CreateRoom()
	{
		return new SpecialRoom();
	}

};

int mainmaze(int argc, char *argv[])
{
	Maze *pMaze = new SpecialMaze();
	Room *pRoom = pMaze->CreateRoom();
	cout << pRoom->getname() << endl;

	return 0;

}

