#include<string>
#include<iostream>
#include<thread>

using namespace std;


class Fctor
{
public:

//    void operator()()
//    {
//        for(int i=0; i>-100; i--)
//        {
//            cout << "from thread:" << i << endl;
//        }
//
//    }

    void operator()(string& msg)
    {
        cout << "t1 says:" << msg << endl;
        msg = "visca el barca";
    }
};

void f2()
{
    cout << "beauty is only skin deep" << endl;
}

//int main()
//{
//    thread t1(f2);
//    //method2:use RAII
//    //wrapper class w(t1)
//    //t1.join in destructor of class w
//
//    try
//    {
//        for(int i=0; i<100; i++)
//        {
//            cout << "from main:" << i << endl;
//        }
//
//    }catch(...)
//    {
//        t1.join();
//        throw;
//    }
//    t1.join();
//
//
//    //use of functors
////    Fctor fct;
////    thread t2(fct);
////
////    t2.join();
//
//
//    //pass by reference
//    string msg = "test message";
//    //Fctor fct1;
//    thread t3((Fctor()), std::ref(msg));//causes data race
//    //thread t3((Fctor()), std::move(msg));
//    thread t4 = std::move(t3);
//    t4.join();
//
//    cout << "from main:" << msg << endl;
//
//    //Thread ID
//    cout << std::this_thread::get_id() << endl;
//    cout << t4.get_id() << endl;
//
//    //Oversubscription
//    std::thread::hardware_concurrency();
//
//    return 0;
//}
