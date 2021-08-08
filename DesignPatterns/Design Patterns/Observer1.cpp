#include<iostream>
#include<vector>

using namespace std;


class Observer1
{
public:

    virtual void update(int runs, int wickets,
                       float overs)=0;
};

class Subject1
{
public:

    virtual void registerObserver(Observer1* o)=0;
    virtual void unregisterObserver()=0;
    virtual void notifyObservers()=0;
};

class CricketData : public Subject1
{
    int runs;
    int wickets;
    float overs;
    vector<Observer1*> observerList;

    int getLatestRuns()
    {
        // return 90 for simplicity
        return runs + 30;
    }

    // get latest wickets from stadium
    int getLatestWickets()
    {
        // return 2 for simplicity
        return wickets + 1;
    }

    // get latest overs from stadium
    float getLatestOvers()
    {
        // return 90 for simplicity
        return overs+5;
    }

public:

    CricketData()
    {
        runs = 100;
        wickets = 1;
        overs = 15;
    }

    void registerObserver(Observer1* o) {
        observerList.push_back(o);
    }


    void unregisterObserver() {
        observerList.pop_back();
    }

    void notifyObservers()
    {

        for(unsigned int i = 0; i < observerList.size(); i++)
        {
            observerList[i]->update(runs,wickets,overs);
        }
    }


    // This method is used update displays
    // when data changes
    void dataChanged()
    {
        //get latest data
        runs = getLatestRuns();
        wickets = getLatestWickets();
        overs = getLatestOvers();

        notifyObservers();
    }
};


class AvgScore : public Observer1
{
    float _runRate;
    int _predictedScore;

 public:

    void update(int runs, int wickets,
                       float overs)
    {
        _runRate =(float)runs/overs;
        _predictedScore = (int)(_runRate * 50);
        display();
    }

    void display()
    {
        cout << "\nAverage Score Display: \n"
                           << "Run Rate: " << _runRate <<
                           "\nPredictedScore: " <<
                           _predictedScore << endl;
    }
};


class CurScore : public Observer1
{
    int _runs, _wickets;
    float _overs;

 public:

    void update(int runs, int wickets,
                       float overs)
    {
        _runs = runs;
        _wickets = wickets;
        _overs = overs;
        display();
    }

    void display()
    {
        cout << "\nCurrent Score Display: \n"
                           << "Runs: " << _runs <<
                           "\nWickets: " <<
                           _wickets << "\nOvers:" << _overs << endl;
    }
};


//int main()
//{
//    AvgScore* averageScoreDisplay = new AvgScore();
//    CurScore* CurScore1 = new CurScore();
//
//    // pass the displays to Cricket data
//    CricketData* cricketData = new CricketData();
//
//    // register display elements
//    cricketData->registerObserver(averageScoreDisplay);
//    cricketData->registerObserver(CurScore1);
//
//    // in real app you would have some logic to
//    // call this function when data changes
//    cricketData->dataChanged();
//
//    //remove an observer
//    //cricketData.unregisterObserver(averageScoreDisplay);
//
//    // now only currentScoreDisplay gets the
//    // notification
//    cricketData->dataChanged();
//
//
//    return 0;
//}


