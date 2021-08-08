#include<iostream>
#include<string>
#include<vector>

using namespace std;


class Notification
{
    string kNotification;

public:

    Notification(const string iNotification)
    {
        kNotification = iNotification;
    }

    void getNotification()
    {
        cout << kNotification << endl;
    }
};

class Iterator
{
public:
    virtual bool hasNext()=0;

    virtual Notification* next()=0;
};

class NotificationIterator : public Iterator
{
    vector<Notification*> notificationList;

    // maintains curr pos of iterator over the array
    //int pos = 0;

 public:
    // Constructor takes the array of notifiactionList are
    // going to iterate over.
    NotificationIterator (vector<Notification*> iNotificationList)
    {
        notificationList = iNotificationList;
    }

    Notification* next()
    {
        // return next element in the array and increment pos
        Notification* notification =  notificationList.back();
        notificationList.pop_back();
        //pos += 1;
        return notification;
    }

    bool hasNext()
    {
        if (!notificationList.empty())
            return false;
        else
            return true;
    }
};

class Collection
{
public:

    virtual Iterator* createIterator()=0;
};


class NotificationCollection : public Collection
{
    static const int MAX_ITEMS = 6;
    int numberOfItems = 0;
    vector<Notification*> notificationList;

 public:
    NotificationCollection()
    {
        //notificationList = new Notification[MAX_ITEMS];

        // Let us add some dummy notifications
        addItem("Notification 1");
        addItem("Notification 2");
        addItem("Notification 3");
    }

    void addItem(const string& str)
    {
        Notification* notification = new Notification(str);
        if (numberOfItems >= MAX_ITEMS)
            cout << "List Full " << endl;
        else
        {
            //notificationList[numberOfItems] = notification;
            notificationList.push_back(notification);
            numberOfItems += 1;
        }
    }

    Iterator* createIterator()
    {
        return new NotificationIterator(notificationList);
    }
};


class NotificationBar
{
    NotificationCollection* notifications;

 public:

    NotificationBar(NotificationCollection* iNotifications)
    {
        notifications = iNotifications;
    }

    void printNotifications()
    {
        Iterator* aIterator = notifications->createIterator();

        while (aIterator->hasNext())
        {
            Notification* n = aIterator->next();
            n->getNotification();
        }
    }
};


//int main()
//{
//    NotificationCollection* nc = new NotificationCollection();
//    NotificationBar* nb = new NotificationBar(nc);
//    nb->printNotifications();
//
//    return 0;
//}
