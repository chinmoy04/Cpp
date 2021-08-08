#include<iostream>
#include<thread>
#include<mutex>
#include<string>
#include<fstream>
#include<deque>
#include<condition_variable>
#include<future>

using namespace std;

int factorial(int N)
{
    int res = 1;
    //int N = f.get();//exception: std::future_errc::broken_promise

    for(int i=1; i<=N; i++)
    {
        res *= i;
    }

    return res;
}


//int main() {
//    /* thread */
//    std::thread t1(factorial, 6);
//    std::this_thread::sleep_for(chrono::milliseconds(3));
//    chrono::steady_clock::time_point tp = chrono::steady_clock::now() + chrono::microseconds(4);
//    std::this_thread::sleep_until(tp);
//
//    /* Mutex */
//    std::mutex mu;
//    std::lock_guard<mutex> locker(mu);
//    std::unique_lock<mutex> ulocker(mu);
//    ulocker.try_lock();
//    ulocker.try_lock_for(chrono::nanoseconds(500));
//    ulocker.try_lock_until(tp);
//
//    /* Condition Variable */
//    std:condition_variable cond;
//    cond.wait_for(ulocker, chrono::microseconds(2));
//    cond.wait_until(ulocker, tp);
//
//    /* Future and Promise */
//    std::promise<int> p;
//    std::future<int> f = p.get_future();
//    f.get();
//    f.wait();
//    f.wait_for(chrono::milliseconds(2));
//    f.wait_until(tp);
//
//    /* async() */
//    std::future<int> fu = async(factorial, 6);
//
//    /* Packaged Task */
//    std::packaged_task<int(int)> t(factorial);
//    std::future<int> fu2 = t.get_future();
//    t(6);
//
//	 return 0;
//}
