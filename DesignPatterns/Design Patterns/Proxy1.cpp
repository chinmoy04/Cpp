//Proxy DP can use a IS-A relationship as well
#include<iostream>

class Player
{
    int id;

public:

    virtual void sendMessage()
    {
        std::cout << "In Actual Player" << std::endl;
    }
};

class PlayerProxy : public Player
{

public:

    void sendMessage()
    {
        if(true)
        {
            std::cout << "Connectivity issue" << std::endl;
        }
        else
        {
            Player::sendMessage();
        }
    }

};

int main0()
{
    Player* p1 = new PlayerProxy();
    p1->sendMessage();

    getchar();

    return 0;
}
