#include<string>
#include "IOInterface.h"

using namespace std;
//Adapter Demo
class IOFSimple : public IOInterface
{
    int open()
    {

    }
    int close();
    int read(char *rd_data, int read_unit_size, int read_len);
    int write(const char *wr_data, int write_unit_size, int write_len);
};


