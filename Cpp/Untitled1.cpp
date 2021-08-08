#include <iostream>
using namespace std;

void fun()
{
	throw 10;
}

int main() {

    try{
        fun();
    }catch(const std::exception& e){
        cout << "test" << e.what() << endl;
    }catch(...)
    {
        cout << "test" << endl;
    }

	// your code goes here
	return 0;
}
