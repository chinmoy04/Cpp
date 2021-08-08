#include<iostream>
#include<thread>
#include<mutex>

using namespace std;
std::mutex mu_1;

void shd_print(int i)
{
    //mu_1.lock();
    std::lock_guard<std::mutex> guard(mu_1);
    cout << i << endl;
    //mu_1.unlock();
}

void f_odd()
{
    int i = 1;

    while(i <= 99)
    {
        shd_print(i);
        i += 2;
    }
}


void f_even()
{
//    std::thread t1(f_even);
    std::thread t2(f_odd);

//    t1.join();


    int i = 0;

    while(i <= 100)
    {
        shd_print(i);
        i += 2;
    }

    t2.join();
}


//int main()
//{
//    f_even();
//
//    return 0;
//}
