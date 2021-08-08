#include <iostream>
#include <vector>

using namespace std;
class Document
{
public:
    void Open() {}
    void DoRead() {}
};

class Application
{
    vector<Document*> docs;
public:
    void AddDocument(Document *pdoc)
    {
        docs.push_back(pdoc);
    }
    virtual void AboutToOpenDocument(Document *pdoc) = 0;
    virtual bool CanOpenDocument(const char *) = 0;
    virtual Document *DoCreateDocument()=0;
    virtual ~Application() {}


    void OpenDocument(const char* name)
    {
        if (!CanOpenDocument(name))
        {
// cannot handle this document
            return;
        }
        Document* doc = DoCreateDocument();
        if (doc)
        {
            AddDocument(doc);
            AboutToOpenDocument(doc);
            doc->Open();
            doc->DoRead();
        }
    }
};


class MyApplication: public Application
{
    public:
    void AboutToOpenDocument(Document *doc) {}

    Document * DoCreateDocument()
    {
        return new Document();
    }
    bool CanOpenDocument(const char *fname)
    {
        return true;
    }
    virtual ~MyApplication()   // delete docs }
    {

    }
};

    int main()
    {
        MyApplication a;
        a.OpenDocument("docfile.x");

        return 0;
    }
