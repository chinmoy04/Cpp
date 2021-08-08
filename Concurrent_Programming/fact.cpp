using namespace std;
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>


std::mutex mtx;
std::condition_variable cv;

bool fnd(int arr[], int n, int k)
{

    for(int i=0 ; i<n ; i++)
        if(arr[i] == k)
            return true;
    return false;
}

void fun(int arr[], int &i,int n, bool& pr, bool& rdy)
{
    while(i<arr[n-1])
    {
        std::unique_lock<std::mutex> guard(mtx);
        cv.wait(guard, [&](){return !rdy;});
        ++i;
        //cout<<""<<i;

        rdy = fnd(arr,n,i);
        guard.unlock();
        if(rdy)
            cv.notify_one();
        //std::this_thread::sleep_for(chrono::seconds(1));
    }
    pr = true;
}

int fact(int i)
{
    int res =1;
    for (int j=i ; j>0 ; j--)
        res*=j;
    return res;

}
void fun1(int& i,bool& pr,bool& rdy)
{
    while(!pr)
    {
        std::unique_lock<std::mutex> guard(mtx);
        cv.wait(guard, [&](){return rdy;});
        int res =1;
        for (int j=i ; j>0 ; j--)
            res= res*j;
        cout<<"IN FUN 2 : "<<i<<" : "<<res<<endl;
        rdy = false;
        guard.unlock();
        cv.notify_one();
    }
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    int i=0;
    bool pr = false, rdy = false;
    std::thread t1(fun,arr,std::ref(i),5,std::ref(pr),std::ref(rdy));
    std::thread t2(fun1,std::ref(i),std::ref(pr),std::ref(rdy));
    t1.join();
    t2.join();
    return 0;
}
