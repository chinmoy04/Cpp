#include<iostream>
#include<thread>
#include<mutex>
#include<string>
#include<fstream>
#include<deque>
#include<condition_variable>

using namespace std;

std::mutex mu1;
std::deque<int> q;
std::condition_variable cond;

void function_1()
{
    int count = 10;
    while(count > 0)
    {
        std::unique_lock<std::mutex> locker(mu1);
        q.push_front(count);
        locker.unlock();
        cond.notify_one();
        cond.notify_all();
        std::this_thread::sleep_for(chrono::seconds(1));
        count--;
    }
}

void function_2()
{
    int data = 0;
    while(data != 1)
    {
        std::unique_lock<std::mutex> locker(mu1);
        cond.wait(locker, [](){return !q.empty();});
        data = q.back();
        q.pop_back();
        locker.unlock();
        cout << "t2 got a value from t1:" << data << endl;
    }
}


//int main()
//{
//    std::thread t1(function_1);
//    std::thread t2(function_2);
//
//    t1.join();
//    t2.join();
//    return 0;
//}
