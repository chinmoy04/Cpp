#include<iostream>
#include<thread>
#include<mutex>
#include<string>
#include<fstream>
#include<deque>
#include<condition_variable>
#include<future>


using namespace std;


//int factorial(std::future<int>& f)
//{
//    int res = 1;
//    int N = f.get();//exception: std::future_errc::broken_promise
//
//    for(int i=1; i<=N; i++)
//    {
//        res *= i;
//    }
//
//    return res;
//}


//shared_future is pass by value
int factorial(std::shared_future<int> f)
{
    int res = 1;
    int N = f.get();//exception: std::future_errc::broken_promise

    for(int i=1; i<=N; i++)
    {
        res *= i;
    }

    return res;
}

//int main()
//{
//    //std::future<int> fu = std::async(factorial, 5);
//    //std::future<int> fu = std::async(std::launch::async, factorial, 5); //creates thread
//    //std::future<int> fu = std::async(std::launch::deferred, factorial, 5);//deferres the creation of a new thread and executed in the same thread
//    std::promise<int> p;
//    std::future<int> f = p.get_future();
//    //std::future<int> fu = std::async(std::launch::deferred, factorial, std::ref(f));
//
//    std::shared_future<int> sf = f.share();
//    std::future<int> fu = std::async(std::launch::deferred, factorial, sf);
//    std::future<int> fu2 = std::async(std::launch::deferred, factorial, sf);
//    std::future<int> fu3 = std::async(std::launch::deferred, factorial, sf);
//    //10 thread
//
//
//    //do something else
//    std::this_thread::sleep_for(chrono::milliseconds(20));
//    //p.set_exception(std::make_exception_ptr(std::runtime_error("OOPS")));
//    p.set_value(5);
//    int x = fu.get();//.get() should be called only once
//    int x1 = fu2.get();//.get() should be called only once
//    int x2 = fu3.get();//.get() should be called only once
//    cout << "factorial:" << x << x1 << x2 << endl;
//
//    //Promise and future cannot be copied only moved
//
//    return 0;
//}
