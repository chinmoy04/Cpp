#include<iostream>
#include<thread>
#include<mutex>
#include<string>
#include<fstream>

using namespace std;

std::mutex mu;

/*
Avoiding Data Race:
1.Use Mutex
2.Never leak a handle of data to outside world
3.Design interface properly
*/



void shared_print(const std::string& msg, int id)
{
    //mu.lock();
    std::lock_guard<std::mutex> guard(mu);//RAII
    cout << msg << id << endl;

    //mu.unlock();
}


void func1()
{
    for(int i=0; i>-100; i--)
    {
        shared_print(string("from thread:"), i);
    }
}

class LogFile
{
    std::mutex m_mutex;
    ofstream f;

public:
    LogFile()
    {
        f.open("threads_ch2.cc");
    }

    void shared_print1(const std::string& msg, int value)
    {
        std::lock_guard<std::mutex> guard(m_mutex);
        f << "from" << msg << ":" << value << endl;
    }

    //Never return f to the outside world
    ofstream& getStream(){return f;}

    //Never pass f as an argument to user function
    void processf(void fun(ofstream&))
    {
        fun(f);
    }
};


//class Stack
//{
//    std::mutex _mu;
//    int *_data;
//
//public:
//    int& pop();
//    int* top();
//};
//
//void func3(Stack& st)
//{
//    int v = st.pop();
//    //any test function ex. process();
//}

void func2(LogFile& log)
{
    for(int i=0; i>-100; i--)
    {
        log.shared_print1(string("from thread:"), i);
    }
}

//int main()
//{
//    thread t1(func1);
//
//    for(int i=0; i<100; i++)
//    {
//        shared_print(string("from main:"), i);
//    }
//
//    t1.join();
//
//    //explicit binding of resource and lock
////    LogFile log;
////    std::thread t2(func2, std::ref(log));
////    for(int i=0; i<100; i++)
////    {
////        log.shared_print1(string("from main:"), i);
////    }
////    t2.join();
//
//    return 0;
//}
