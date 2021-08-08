#include<iostream>
#include<thread>
#include<mutex>
#include<string>
#include<fstream>

using namespace std;

//std::mutex mu;

class LogFile1
{
    std::mutex m_mutex;
    std::mutex m_mutex2;
    ofstream f;

public:
    LogFile1()
    {
        f.open("threads_ch2.cc");
    }

    void shared_print1(const std::string& msg, int value)
    {
//        std::lock_guard<std::mutex> guard(m_mutex);
//        std::lock_guard<std::mutex> guard2(m_mutex2);
        //OR
        std::lock(m_mutex, m_mutex2);
        std::lock_guard<std::mutex> guard(m_mutex, std::adopt_lock);
        std::lock_guard<std::mutex> guard2(m_mutex2, std::adopt_lock);
        cout << "from" << msg << ":" << value << endl;
    }

    void shared_print2(const std::string& msg, int value)
    {
        //std::lock_guard<std::mutex> guard2(m_mutex2);//creates a deadlock
//        std::lock_guard<std::mutex> guard(m_mutex);
//        std::lock_guard<std::mutex> guard2(m_mutex2);// lock mutex in the same order to avoid deadlock

        //OR
        std::lock(m_mutex, m_mutex2);
        std::lock_guard<std::mutex> guard(m_mutex, std::adopt_lock);
        std::lock_guard<std::mutex> guard2(m_mutex2, std::adopt_lock);
        cout << "from" << msg << ":" << value << endl;
    }

    //Never return f to the outside world
    ofstream& getStream(){return f;}

    //Never pass f as an argument to user function
    void processf(void fun(ofstream&))
    {
        fun(f);
    }
};


void fun2(LogFile1& log)
{
    for(int i=0; i>-100; i--)
    {
        log.shared_print1(string("from thread:"), i);
    }
}


/*
Avoiding Deadlock:
1.Prefer locking single mutex
2.Avoid locking a mutex and calling a user function which may also try to lock the same mutex
3.Use std::lock to lock more than one mutex
4.Lock the mutex in the same order
*/


//int main()
//{
//    LogFile1 log;
//    std::thread t2(fun2, std::ref(log));
//    for(int i=0; i<100; i++)
//    {
//        log.shared_print2(string("from main:"), i);
//    }
//    t2.join();
//    return 0;
//}
