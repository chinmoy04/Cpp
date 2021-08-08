#include<iostream>

using namespace std;

//Receiver
class WordDoc
{
public:

    void open()
    {
        cout << "Open Doc" << endl;
    }

    void close()
    {
        cout << "Close Doc" << endl;
    }

    void save()
    {
        cout << "Save Doc" << endl;
    }
};


class Command
{
public:

    virtual void execute()=0;
};

class OpenCommand : public Command
{
    WordDoc pWordDoc;

public:

    OpenCommand(WordDoc iWordDoc)
    {
        pWordDoc = iWordDoc;
    }

    void execute()
    {
        pWordDoc.open();
    }
};


class CloseCommand : public Command
{
    WordDoc pWordDoc;

public:

    CloseCommand(WordDoc iWordDoc)
    {
        pWordDoc = iWordDoc;
    }

    void execute()
    {
        pWordDoc.close();
    }
};


class SaveCommand : public Command
{
    WordDoc pWordDoc;

public:

    SaveCommand(WordDoc iWordDoc)
    {
        pWordDoc = iWordDoc;
    }

    void execute()
    {
        pWordDoc.save();
    }
};


class MenuOptions
{
    Command* _pOpen;
    Command* _pClose;
    Command* _pSave;

public:

    MenuOptions(Command* iOpen, Command* iClose, Command* iSave)
    {
        _pOpen = iOpen;
        _pClose = iClose;
        _pSave = iSave;
    }

    void clickOpen()
    {
        _pOpen->execute();
    }

    void clickClose()
    {
        _pClose->execute();
    }

    void clickSave()
    {
        _pSave->execute();
    }
};


//int main()
//{
//    WordDoc w1;
//
//    Command* c1 = new OpenCommand(w1);
//    Command* c2 = new CloseCommand(w1);
//    Command* c3 = new SaveCommand(w1);
//
//    MenuOptions m1(c1, c2, c3);
//
//    m1.clickOpen();
//    m1.clickSave();
//    m1.clickClose();
//
//
//    return 0;
//}
