#include<iostream>
#include<thread>
#include<mutex>
#include<string>
#include<fstream>

using namespace std;


class LogFile2
{
    std::mutex m_mutex;
    std::mutex m_mutex_open;
    std::once_flag _flag;
    ofstream f;

public:
    LogFile2()
    {
        //early initialization
        //f.open("threads_ch2.cc");
    }

    void shared_print1(const std::string& msg, int value)
    {
        //Lazy initialization
//        {
//            std::unique_lock<std::mutex> locker3(m_mutex_open);
//            if(!f.is_open())
//            {
//                f.open("threads_ch2.cc");
//            }
//        }
        //OR
        std::call_once(_flag, [&](){f.open("threads_ch2.cc");});


        //std::lock_guard<std::mutex> guard(m_mutex);
        std::unique_lock<std::mutex> locker(m_mutex, std::defer_lock);
        //do somrthing
        locker.lock();
        f << "from" << msg << ":" << value << endl;
        locker.unlock();

        //do something else

        locker.lock();
        std::unique_lock<std::mutex> locker2 = std::move(locker);
        locker2.unlock();

        /*
        lock_guard cannot be copied or moved
        unique_lock is heavy
        */
    }


    //Never return f to the outside world
    ofstream& getStream(){return f;}

    //Never pass f as an argument to user function
    void processf(void fun(ofstream&))
    {
        fun(f);
    }
};



//int main()
//{
//    return 0;
//}
