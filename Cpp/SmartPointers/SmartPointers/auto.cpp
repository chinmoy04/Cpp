#include<iostream>
#include<memory>

using namespace std;

class A
{
public:
    void show()
    {
        cout << "Inside class A" << endl;
    }
};

//int main()
//{
//    auto_ptr<A> aPtr(new A());
//
//    aPtr->show();
//    cout << aPtr.get()<< endl;
//
//    auto_ptr<A> bPtr(aPtr);
//    bPtr->show();
//    aPtr->show();
//    cout << aPtr.get()<< endl;
//    cout << bPtr.get();
//
//    return 0;
//}
