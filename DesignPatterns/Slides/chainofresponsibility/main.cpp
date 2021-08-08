// ChainOfResponsibility.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#define BASE_AMOUNT_APPROVAL 1000
class ExpenseApprover
{
protected:
	ExpenseApprover *successor;

public:
	ExpenseApprover *getSuccessor()
	{
		return successor;
	}

	void setSuccessor(ExpenseApprover *ea)
	{
		successor = ea;
	}

	virtual const char *getName() = 0;

	virtual int getLimit() = 0;
	virtual bool ProcessRequest(int amount)
	{

		if (amount <= getLimit())
		{
			cout << "requested amount:" << amount << " approved by " << getName() << endl;
			return true;
		}
		else
		{
			if (getSuccessor() != NULL)
			{
				return getSuccessor()->ProcessRequest(amount);
			}
		}
		return false;
	}

};


class DirectorEA : public ExpenseApprover
{
public:
	virtual int getLimit()
	{
		return BASE_AMOUNT_APPROVAL * 100;
	}

	virtual const char *getName()
	{
		return "Director";
	}


};

class ManagerEA : public ExpenseApprover
{
public:
	virtual int getLimit()
	{
		return BASE_AMOUNT_APPROVAL * 5;
	}

	virtual const char *getName()
	{
		return "Manager";
	}

};


class EngineerEA : public ExpenseApprover
{
public:
	virtual int getLimit()
	{
		return BASE_AMOUNT_APPROVAL * 2;
	}

	virtual const char *getName()
	{
		return "Engineer";
	}

};



int main()
{
	ExpenseApprover *ptr1;
	ExpenseApprover *ptr2;
	ExpenseApprover *ptr3;

	ptr1 = new EngineerEA();
	ptr2 = new ManagerEA();
	ptr3 = new DirectorEA();

	ptr1->setSuccessor(ptr2);
	ptr2->setSuccessor(ptr3);
	ptr3->setSuccessor(NULL);

	ptr1->ProcessRequest(1000);
	ptr1->ProcessRequest(2000);
	ptr1->ProcessRequest(5000);


	ptr1->ProcessRequest(100000);
	bool retval = ptr1->ProcessRequest(100001);

	if (retval == false)

	{
		cout << "no approver for 100001" << endl;
	}


	return 0;
}



#ifdef xxx
#define BASE_AMOUNT_APPROVAL 1000
class ExpenseApprover
{
protected:
	ExpenseApprover *successor;

public:
	ExpenseApprover *getSuccessor()
	{
		return successor;
	}

	void setSuccessor(ExpenseApprover *ea)
	{
		successor = ea;
	}

	virtual int getLimit() = 0;
	virtual bool ProcessRequest(int amount) = 0;
};


class DirectorEA : public ExpenseApprover
{
public:
	virtual int getLimit()
	{
		return BASE_AMOUNT_APPROVAL * 10;
	}

	virtual const char *getName()
	{
		return "Director";
	}

	virtual bool ProcessRequest(int amount)
	{
		cout << "requested amount:" << amount << " approved by " << getName() << endl;
		return true;


	}

};

class ManagerEA : public ExpenseApprover
{
public:
	virtual int getLimit()
	{
		return BASE_AMOUNT_APPROVAL * 5;
	}
	virtual bool ProcessRequest(int amount)
	{
		cout << "requested amount:" << amount << " approved by " << getName() << endl;

		if (amount > getLimit())
		{
			return getSuccessor()->ProcessRequest(amount);
		}
		return true;

	}

	virtual const char *getName()
	{
		return "Manager";
	}

};


class EngineerEA : public ExpenseApprover
{
public:
	virtual int getLimit()
	{
		return BASE_AMOUNT_APPROVAL * 2;
	}
	virtual bool ProcessRequest(int amount)
	{
		cout << "requested amount:" << amount << " approved by " << getName() << endl;

		if (amount > getLimit())
		{
			return getSuccessor()->ProcessRequest(amount);
		}
		return true;
	}

	virtual const char *getName()
	{
		return "Engineer";
	}

};



int main(int argc, _TCHAR* argv[])
{
	ExpenseApprover *ptr1;
	ExpenseApprover *ptr2;
	ExpenseApprover *ptr3;

	ptr1 = new EngineerEA();
	ptr2 = new ManagerEA();
	ptr1->setSuccessor(ptr2);
	ptr3 = new DirectorEA();
	ptr2->setSuccessor(ptr3);

	ptr1->ProcessRequest(5000);
	bool retval = ptr1->ProcessRequest(15000);


	return 0;
}

#endif
