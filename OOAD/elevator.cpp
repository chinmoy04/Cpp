#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#define RANGE 255

using namespace std;



class elevator{
private:
    //The Lift box the elevator controls
    liftboxControlUnit & mLiftBoxCtrlUnit;

    //constructor
    elevator(int Level=1, int NoOfBanks =1 );

    //Destructor
    ~elevator();

    //Triggers the search to move to the next floor if required
    void moveLiftToNext();

public:

    //Adds request to the queue
    void addRequest(int FloorNumber){

    //Add the request to the queue. The single button outside the elevator door
    mLiftBoxCtrlUnit.addRequest(FloorNumber);

    }

    //For Emergency. Should be accessible to everyone !
    void setEmergency();
    void unsetEmergency();

};

typedef enum Direction{
    UP,
    DOWN
}direction;

class liftboxControlUnit{
private:

    //The request for various floors
    set<int> mRequestQueue;

    //The various banks for the whole system
    vector<Bank> mBanks;

    //The total number of levels. Remains the same for one building
    const int mTotalLevel;

    //Instruction to move the box to certain level
    void processRequest(){

        //Do the logic to move the box.

    }

    //can passed to the elevator
    void addRequest(int x){
        mRequestQueue.insert(x);
    }

    //Can be set by elevator class
    void setEmergency(){
        //Do the required
        //Set Emergency on all Banks
    }

    void unsetEmergency(){
        //UnsetEmegency on all banks
    }

    void emergencyListener(){
        //Listen to all the banks if emergency has been set
    }

    void BankFreeListener(){
        //Listen to the banks if any is free

        //If so then
        processRequest();
    }

public:
    //Constructor
    liftboxControlUnit(int TotalLevels, int NoOfBanks): mTotalLevel(TotalLevels){
        for(int i=0 ; i lessthan NoOfBanks; ++ i)
            mBanks.push_back(Bank(0,UP));
    }
    friend class elevator;
};

class Bank{
private:

    //The dailpad inside the bank
    dailpad & mpad;

    //Current Location
    int mPresentLevel;

    //Current direction of movement
    direction mDirection;

    //Currently moving
    bool mEngaged;

    //Manipulate the bank
    void move(int NoOfMoves){
        setEngaged();

        //Move the elevator

        unsetEngaged();
    }

    //getters
    int getPresentLevel() const;
    int getDirection() const;

    //setters
    void setPresentLevel(int);
    void setDirection(direction);

    //Manipulate the engaged flag
    bool isEngaged() const;
    bool setEngaged();
    bool unsetEngaged();

    //For emergency
    void reset();

    //Dailpad Listener
    void dailpadListener(){

    }


public:
    Bank(int StartingLevel, direction Direction): mPresentLevel(StartingLevel),
            mDirection(Direction),
            mEngaged(false),
            mpad()
    {

    }

    //For emergency . Should be available for all.
    void SetEmergency();
    void UnsetEmergency();
    bool isEmergency();

    friend class liftboxControlUnit;
};


class dailpad{

private:
    //Some DS to represent the state . probably a 2D Array.

    void renderDisplay();

public:

    //Constructor
    dailpad();

    void getCommand(int x){
        //Depending on the value we can do the following

        //Make necessary changes to the display
        renderDisplay();
    }

    friend class Bank;
};
