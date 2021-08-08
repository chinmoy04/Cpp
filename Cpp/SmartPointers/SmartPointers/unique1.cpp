#include<iostream>
#include<memory>

using namespace std;

class B
{
public:
    void show()
    {
        cout << "Inside class B" << endl;
    }
};


//int main()
//{
//    unique_ptr<B> aPtr(new B);
//    aPtr->show();
//
//    unique_ptr<B> bPtr = move(aPtr);
//    bPtr->show();
//    aPtr->show();
//    cout << bPtr.get() << endl;
//    cout << aPtr.get();
//
//    return 0;
//
//}
