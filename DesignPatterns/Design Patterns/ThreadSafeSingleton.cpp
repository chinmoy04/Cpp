#include<iostream>
#include<atomic>
#include<mutex>

using namespace std;

class Foo {
public:
    static Foo* Instance();
private:
    Foo() {}
    static atomic<Foo*> pinstance;
    static mutex m_;
};

atomic<Foo*> Foo::pinstance { nullptr };
std::mutex Foo::m_;

Foo* Foo::Instance()
{
  if(pinstance == nullptr)
  {
    lock_guard<mutex> lock(m_);
    if(pinstance == nullptr) {
        pinstance = new Foo();
    }
  }
  return pinstance;
}


//int main()
//{
//    return 0;
//}
