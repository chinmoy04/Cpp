#include<iostream>
#include<thread>
#include<mutex>
#include<string>
#include<fstream>
#include<deque>
#include<condition_variable>
#include<future>

using namespace std;

int factorial1(int N)
{
    int res = 1;

    for(int i=1; i<=N; i++)
    {
        res *= i;
    }

    return res;
}

std::deque<std::packaged_task<int()> > task_q;
std::mutex mu4;
std::condition_variable cond1;

void thread_1()
{
    std::packaged_task<int()> t;
    {
        std::unique_lock<std::mutex> locker(mu4);
        cond1.wait(locker, [](){return !task_q.empty();});
        t = std::move(task_q.front());
    }

    t();
}

//int main()
//{
//    //std::thread t1(factorial1, 6);
//    std::thread t1(thread_1);
//    //std::packaged_task<int(int)> t(factorial1);
//    std::packaged_task<int()> t(std::bind(factorial1, 6));
//    // auto t = std::bind(factorial1, 6);
//    //do something
//
//    //t(6);//in a different context
//    //int x = t.get_future().get();
//    std::future<int> fu = t.get_future();
//    {
//        std::lock_guard<std::mutex> locker(mu4);
//        task_q.push_back(t);
//
//    }
//    cond1.notify_one();
//
//    int x = fu.get();
//    cout << x << endl;
//    //t1();
//
//    t1.join();
//
//    return 0;
//}
