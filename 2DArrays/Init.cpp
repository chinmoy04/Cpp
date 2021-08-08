#include<iostream>
#include<stdlib.h>

using namespace std;

void printArray(int r, int c, int *arr)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout << *(arr + i*c + j) << "\t";
        }
        cout << endl;
    }
}

void singlePtr(int r, int c)
{
    int *arr = (int *)malloc(r*c*sizeof(int));

    int i, j, count=0;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            *(arr + i*c + j) = ++count;
        }
    }

    printArray(r, c, (int *)arr);
}

void ptrArray(int r, int c)
{
    int i, j, count=0;
    int *arr[r];

    for(i=0; i<r; i++)
        arr[i] = (int *)malloc(c*sizeof(int));

    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            *(*(arr + i) + j) = ++count;
        }
    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout << *(*(arr + i) + j) << "\t";
        }
        cout << endl;
    }
}

void doublePtr(int r, int c)
{
    int i, j, count=0;

    int **arr =(int **)malloc(sizeof(int *));
    for(i=0; i<r; i++)
        arr[i] = (int *)malloc(c*sizeof(int));


    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            *(*(arr + i) + j) = ++count;
        }
    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout << *(*(arr + i) + j) << "\t";
        }
        cout << endl;
    }
}

void doublePtr1(int r, int c)
{
    int i, j, count=0;

    int **arr =(int **)malloc(sizeof(int *));

    arr[0] = (int *)malloc(r*c*sizeof(int));

    for(i = 0; i < r; i++)
        arr[i] = (*arr + c * i);


    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            *(*(arr + i) + j) = ++count;
        }
    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout << *(*(arr + i) + j) << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int r=3, c=4;
    singlePtr(r, c);
    ptrArray(r, c);
    doublePtr(c, r);
    doublePtr1(c, r);

    return 0;
}

