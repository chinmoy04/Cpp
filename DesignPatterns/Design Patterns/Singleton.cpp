#include<iostream>
#include<string>

class Logger
{
public:
    static Logger* getInstance()
    {
        if(_instance == NULL)
        {
            _instance = new Logger();
        }

        return _instance;
    }

    void open()
    {
        std::cout << "Inside Open" << std::endl;
    }

    void close()
    {
        std::cout << "Inside Close" << std::endl;
    }

protected:
    Logger();

private:
    static Logger* _instance;

};

//int main1()
//{
//    Logger *log1 = Logger::getInstance();
//    log1->open();
//    log1->close();
//
//    return 0;
//}
