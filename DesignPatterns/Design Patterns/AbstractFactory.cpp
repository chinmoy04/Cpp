#include<iostream>

using namespace std;

class Button
{
public:
    virtual void show()=0;
};

class WindowsButton : public Button
{
public:

    void show()
    {
        cout << "Windows Button" << endl;
    }

};


class LinuxButton : public Button
{
public:

    void show()
    {
        cout << "Linux Button" << endl;
    }

};


class Menu
{
public:
    virtual void display()=0;
};


class WindowsMenu : public Menu
{
public:

    void display()
    {
        cout << "Windows Display" << endl;
    }

};


class LinuxMenu : public Menu
{
public:

    void display()
    {
        cout << "Linux Display" << endl;
    }

};


class WidgetFactory
{
public:

    virtual Menu* createMenu()=0;
    virtual Button* createButton()=0;
};


class WindowsFactory : public WidgetFactory
{
public:
    Menu* createMenu()
    {
        return new WindowsMenu();
    }

    Button* createButton()
    {
        return new WindowsButton();
    }
};

class LinuxFactory : public WidgetFactory
{
public:
    Menu* createMenu()
    {
        return new LinuxMenu();
    }

    Button* createButton()
    {
        return new LinuxButton();
    }
};


class Client1
{
public:

    static WidgetFactory* createWidget(const string& iPlatform)
    {
        if(iPlatform == "WIN32")
        {
            return new WindowsFactory();
        }

        if(iPlatform == "Linux")
        {
            return new LinuxFactory();
        }

        return NULL;
    }

};

//int main()
//{
//    WidgetFactory* aFactory =  Client1::createWidget("WIN32");
//
//    aFactory->createButton()->show();
//
//    WidgetFactory* aFactory1 = Client1::createWidget("Linux");
//
//    aFactory1->createMenu()->display();
//
//    return 0;
//}
