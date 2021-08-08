#include<iostream>

using namespace std;

template<class T>
class SmartPtr
{
    T *t;

public:
    explicit SmartPtr(T *ptr = NULL):t(ptr){}

    T& operator *(){return *t;}
    T* operator ->(){return t;}
};

//int main()
//{
//    SmartPtr<int> sPtr(new int());
//
//    *sPtr = 40;
//    cout << *sPtr;
//}
