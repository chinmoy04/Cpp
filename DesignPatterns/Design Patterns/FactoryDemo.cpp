#include<iostream>
#include<string>

class Product
{
public:
    virtual void getName() = 0;
};

class ProductA : public Product
{
public:
    void getName()
    {
        std::cout << "ProductA" << std::endl;
    }
};

class ProductB : public Product
{
public:
    void getName()
    {
        std::cout << "ProductA" << std::endl;
    }
};

class Creator
{
public:
    virtual Product* create(int id) = 0;
};

class CreateSimple : public Creator
{
public:
    Product* create(int id)
    {
        if(id == 1)
        {
            return new ProductA();
        }
        else if(id == 2)
        {
            return new ProductB();
        }

        return NULL;
    }
};

//int main0()
//{
//    Creator *c1 = new CreateSimple();
//
//    Product *p1 = c1->create(1);
//    Product *p2 = c1->create(2);
//
//    p1->getName();
//    p2->getName();
//
//    getchar();
//    return 0;
//}

