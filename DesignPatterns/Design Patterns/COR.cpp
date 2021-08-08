#include<iostream>
#include<string>

class Employee
{
    Employee* next;
public:
    Employee()
    {
        next = NULL;
    }

    void addEmployee(Employee* e)
    {
        if(next)
        {
            next->addEmployee(e);
        }
        else
        {
            next = e;
        }

    }

    virtual void handleRequest(int i)
    {
//        if(i > 100000)
//        {
//            std::cout << "Request cannot be approved" << std::endl;
//        }
        next->handleRequest(i);
    }
};

class Engineer : public Employee
{
public:
    void handleRequest(int i)
    {
        if(i < 1000)
        {
            std::cout << "Handled by Engineer" << std::endl;
        }
        else
        {
            Employee::handleRequest(i);
        }
    }
};

class Manager : public Employee
{
public:
    void handleRequest(int i)
    {
        if(i>1000 && i < 5000)
        {
            std::cout << "Handled by Manager" << std::endl;
        }
        else
        {
            Employee::handleRequest(i);
        }
    }
};

class Director : public Employee
{
public:
    void handleRequest(int i)
    {
        if(i>5000 && i < 100000)
        {
            std::cout << "Handled by Director" << std::endl;
        }
        else
        {
            Employee::handleRequest(i);
            //std::cout << "Request could not be handled" << std::endl;
        }
    }
};

int main2()
{
    Employee* emp = new Engineer();
    emp->addEmployee(new Manager());
    emp->addEmployee(new Director());

    emp->handleRequest(500);
    emp->handleRequest(1500);
    emp->handleRequest(15000);
    emp->handleRequest(1500000);

    getchar();

    return 0;
}
