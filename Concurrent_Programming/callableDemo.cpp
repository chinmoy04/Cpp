#include<iostream>
#include<thread>
#include<mutex>
#include<string>
#include<fstream>
#include<deque>
#include<condition_variable>
#include<future>

using namespace std;

class A
{
public:
    void f(int x, char c){}
    long g(double x){return 0;}
    int operator()(int N){return 0;}
};

void foo(int x){cout << x << "inside foo" << endl;}

//int main()
//{
//    A a;
//    std::thread t1(a, 6);//copy of a in a different thread
//    std::thread t2(std::ref(a), 6);//a() in a different thread
//    std::thread t3(std::move(a), 6);//a is no longer usable in main thread
//    std::thread t4(A(), 6);//temp A
//    std::thread t5([](int x){return x*x;}, 6);//lambda fn
//    std::thread t6(foo, 6);//copy of a in a different thread
//    std::thread t7(&A::f, a, 8, 'w');//copy of a.f() in a different thread
//    std::thread t8(&A::f, &a, 8, 'w');//a.f() in a different thread
//
//    //we can also use std::bind std::async, std::call_once
//
//    return 0;
//}
