#include<string>
 using namespace std;

class IOInterface
{
protected:
 string filename;
 string rwoptions;
public:
 IOInterface() { rwoptions = "r"; }
 void setfilename(string& fname) { filename = fname; }
 void setrwoptions(string& rwopt) { rwoptions = rwopt; }
 virtual int open()=0;
 virtual int close()=0;
 virtual int read(char *rd_data, int
          read_unit_size, int read_len)=0;
 virtual int write(const char *wr_data, int write_unit_size, int write_len)=0;
};
