// Singleton.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <fstream>

using namespace std;

class Singleton
{
public:
	static Singleton* Instance();
	// constructor is protected, ensures only one instance will be created
protected:
	Singleton() {}
private:
	static Singleton* _instance;

};

Singleton* Singleton::_instance = 0;

Singleton* Singleton::Instance()
{
	// lazy initialization, only with Instance() is requested it initializes _instance
	if (_instance == NULL)
	{
		_instance = new Singleton();
	}
	return _instance;
}



int main2(int argc, char* argv[])
{
	Singleton* pSingleton =  Singleton::Instance();
	Singleton* pSingleton2 = Singleton::Instance();

	return 0;
}

#include <iostream>
#include <fstream>
#include <exception>
#include <stdexcept>
class Logger
{
public:
	static Logger* Instance();
	static void open();
	static void log(const char *message, int log_level);
	static void close();

	// constructor is protected, ensures only one instance will be created
protected:
	Logger() { cout << "Logger constructor" << endl; }
	~Logger() { cout << "Logger destructor" << endl; }

	static int log_level;
	static bool inited;

	static const char * const LogFileName;
	static ofstream ofs;
	friend class deletemem;
	class deletemem
	{
	public:
		~deletemem();
	};

private:
	static Logger* _instance;
};


Logger* Logger::_instance = NULL;
const char* const Logger::LogFileName = "msg.log";
bool Logger::inited = false;
ofstream Logger::ofs;

Logger::deletemem::~deletemem()
{
	cout << "deleted from deletemem" << endl;
	delete _instance;
}

Logger* Logger::Instance()
{
	static deletemem delmem;
	// lazy initialization, only with Instance() is requested it initializes _instance
	if (_instance == NULL)
	{
		_instance = new Logger();
	}
	return _instance;
}

void Logger::open()
{
	if (!inited)
	{
		ofs.open(LogFileName);
		if (!ofs.good())
		{
			throw runtime_error("Unable to initialize");
		}
		inited = true;
	}
}

void Logger::log(const char *msg, int level)
{
	if (!inited) {
		open();
	}
	ofs << level << ":: " << msg<< endl;
}

void Logger::close()
{
	if (inited) {
		ofs.close();
		inited = false;
	}

}

int main(int argc, char* argv[])
{
	Logger* pLogger= Logger::Instance();
	pLogger->log("hello1", 1);
	pLogger->log("hello2", 1);
	pLogger->log("hello3", 1);
	pLogger->close();

	return 0;
}

#ifdef COMPONENT_SERVICE_ENABLE

#include "stdafx.h"
#include <iostream>
#include <sstream>
using namespace std;
#include <map>


class ComponentServiceMap
{
protected:
	static ComponentServiceMap CSMapInstance;
	std::map<string, void *> mComponentBroker;

private:
	ComponentServiceMap() { cout << "in constructor " << endl; }

	virtual ~ComponentServiceMap() { cout << "destructor" << endl; };

public:
	bool RegisterServiceForName(string service_name, void *service_ptr)
	{
		auto res = mComponentBroker.insert(make_pair(service_name, service_ptr));
		return res.second;
	}

	void *LookupServiceByName(string service_name)
	{
		auto it = mComponentBroker.find(service_name);
		if (it == mComponentBroker.end())
		{
			string message = service_name + ": Not Found";
			throw out_of_range(message);
		}
		return it->second;
	}

	void DeleteService(string service_name)
	{
		mComponentBroker.erase(service_name);
	}

	static ComponentServiceMap& GetInstance() { return CSMapInstance; }

};

ComponentServiceMap ComponentServiceMap::CSMapInstance;

int mainzz(int argc, char* argv[])
{
	char *svc_ptr1 = "Time Service"; // this must point to Time Service
	char *svc_ptr2 = "Web Service"; // this must point to Web Service
	string service_name1 = "time";
	string service_name2 = "web";

	ComponentServiceMap::GetInstance().RegisterServiceForName(service_name1, svc_ptr1);
	ComponentServiceMap::GetInstance().RegisterServiceForName(service_name2, svc_ptr2);

	char *sptr1 = static_cast<char *> (ComponentServiceMap::GetInstance().LookupServiceByName("time"));
	cout << "Looking up time service:" << sptr1 << endl;

	char *sptr2 = static_cast<char *> (ComponentServiceMap::GetInstance().LookupServiceByName("web"));
	cout << "Looking up web service:" << sptr2 << endl;
	return 0;
}

#endif
