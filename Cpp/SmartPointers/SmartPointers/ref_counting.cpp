#include<iostream>
#include<memory>

using namespace std;

class RC
{
    private:
    int count; // Reference count

    public:
    void AddRef()
    {
        // Increment the reference count
        count++;
    }

    int Release()
    {
        // Decrement the reference count and
        // return the reference count.
        return --count;
    }
};


template < typename T > class SP
{
private:
    T*    pData;       // pointer
    RC* reference; // Reference count

public:
    SP() : pData(0), reference(0)
    {
        // Create a new reference
        reference = new RC();
        // Increment the reference count
        reference->AddRef();
    }

    SP(T* pValue) : pData(pValue), reference(0)
    {
        // Create a new reference
        reference = new RC();
        // Increment the reference count
        reference->AddRef();
    }

    SP(const SP<T>& sp) : pData(sp.pData), reference(sp.reference)
    {
        // Copy constructor
        // Copy the data and reference pointer
        // and increment the reference count
        reference->AddRef();
    }

    ~SP()
    {
        // Destructor
        // Decrement the reference count
        // if reference become zero delete the data
        if(reference->Release() == 0)
        {
            delete pData;
            delete reference;
        }
    }

    T& operator* ()
    {
        return *pData;
    }

    T* operator-> ()
    {
        return pData;
    }

    SP<T>& operator = (const SP<T>& sp)
    {
        // Assignment operator
        if (this != &sp) // Avoid self assignment
        {
            // Decrement the old reference count
            // if reference become zero delete the old data
            if(reference->Release() == 0)
            {
                delete pData;
                delete reference;
            }

            // Copy the data and reference pointer
            // and increment the reference count
            pData = sp.pData;
            reference = sp.reference;
            reference->AddRef();
        }
        return *this;
    }
};


class PERSON
{
    int age;
    char* pName;

    public:
        PERSON(): pName(0),age(0)
        {
        }
        PERSON(char* pName, int age): pName(pName), age(age)
        {
        }
        ~PERSON()
        {
        }

        void Display()
        {
            //printf("Name = %s Age = %d \n", pName, age);
            cout << age << pName << endl;
        }
        void Shout()
        {
            //printf("Ooooooooooooooooo",);
            cout << "Oooooooooooo" << endl;
        }
};


int main()
{
    SP<PERSON> p(new PERSON("Scott", 25));
    p->Display();
    {
        SP<PERSON> q = p;
        q->Display();
        // Destructor of q will be called here..

        SP<PERSON> r;
        r = p;
        r->Display();
        // Destructor of r will be called here..
    }
    p->Display();
    // Destructor of p will be called here
    // and person pointer will be deleted

    return 0;
}


