#include<iostream>
#include<thread>

using namespace std;


void f1()
{
    cout << "Test" << endl;
}


//int main()
//{
//    thread t1(f1); // t1 starts running
//    //t1.join();// main thread waits for t1 to finish
//    t1.detach();
//
//    if(t1.joinable())
//    {
//        t1.join();//will crash without line no 19
//    }
//
//    return 0;
//}
