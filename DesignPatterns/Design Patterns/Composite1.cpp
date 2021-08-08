#include<iostream>
#include<vector>

using namespace std;

class Employee1
{
public:

    virtual void showDetails()=0;
};


class Developer : public Employee1
{
public:

    void showDetails()
    {
        cout << "Developer class" << endl;
    }
};


class Manager1 : public Employee1
{
public:

    void showDetails()
    {
        cout << "Manager class" << endl;
    }
};


class CompanyDirectory
{
    std::vector<Employee1*> _pEmpVec;

public:

    void addEmployee(Employee1* iEmp)
    {
        _pEmpVec.push_back(iEmp);
    }

    void showEmpDetails()
    {
        for(int i=0; i<_pEmpVec.size(); i++)
        {
            _pEmpVec[i]->showDetails();
        }
    }
} ;


//int main()
//{
//    CompanyDirectory p1;
//
//    for(unsigned int i=0; i<4; i++)
//    {
//        p1.addEmployee(new Developer());
//    }
//
//    for(unsigned int i=0; i<4; i++)
//    {
//        p1.addEmployee(new Manager1());
//    }
//
//    p1.showEmpDetails();
//
//    return 0;
//}
