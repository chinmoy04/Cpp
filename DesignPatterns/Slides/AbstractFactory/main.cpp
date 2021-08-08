// AbstractFactory.cpp : Defines the entry point for the console application.
//
#include <iostream>
using namespace std;

class Window
{
public:
	virtual const char *getName() = 0;
};

class ScrollBar
{
public:
	virtual const char *getName() = 0;

};

class AWindow : public Window
{
public:
	virtual const char *getName()
	{
		return "AWindow";
	}
};

class BWindow : public Window
{
public:
	virtual const char *getName()
	{
		return "BWindow";
	}
};

class AScrollBar : public ScrollBar
{
public:
	virtual const char *getName()
	{
		return "AScrollBar";
	}
};
class BScrollBar : public ScrollBar
{
public:
	virtual const char *getName()
	{
		return "BScrollBar";
	}
};
class WidgetFactory
{
public:
	virtual Window *CreateWindow() = 0;
	virtual ScrollBar *CreateScrollBar() = 0;
};

class AWidgetFactory : public WidgetFactory
{
public:
	virtual Window *CreateWindow()
	{
		return new AWindow();
	}
	virtual ScrollBar *CreateScrollBar()
	{
		return new AScrollBar();
	}
};
class BWidgetFactory : public WidgetFactory
{
public:
	virtual Window *CreateWindow()
	{
		return new BWindow();
	}
	virtual ScrollBar *CreateScrollBar()
	{
		return new BScrollBar();
	}
};

class Client
{
protected:
	WidgetFactory *pwFamily;

public:
	Client(WidgetFactory *_pwFamily)
	{
		pwFamily = _pwFamily;
	}

	Window *CreateWindow()
	{
		return pwFamily->CreateWindow();
	}

	ScrollBar *CreateScrollBar()
	{
		return pwFamily->CreateScrollBar();
	}
};

int main(int argc, char* argv[])
{
	AWidgetFactory awf;
	Client *pClient = new Client(&awf);
	ScrollBar *pScrollBar = pClient->CreateScrollBar();
	Window *pWindow = pClient->CreateWindow();
	std::cout << pScrollBar->getName() << endl;
	std::cout << pWindow->getName() << endl;

	return 0;
}


