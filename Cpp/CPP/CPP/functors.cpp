#include<iostream>
#include<algorithm>

using namespace std;

class increment
{
    int num;

public:
    increment(int n):num(n){}

    int operator()(int arr_num) const
    {
        return arr_num + num;
    }
};


int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int to_add = 8;

    transform(arr, arr+n, arr, increment(to_add));

    for (int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}


