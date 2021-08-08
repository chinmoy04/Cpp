#include<vector>

class Player
{

};

class Move
{
    int spaces;

public:

    void moveStraight();
    void moveLeft();
    void moveRight();
    void moveDiagonal();
    void moveBack();
};

class Peices
{
    Move m1;

public:

    void movePeice();
};

class Board
{
    std::vector<Peices> peiceVec;
};

class ChessGame
{
    Player p1;
    Player p2;
    Board b1;
    Peices p[32];
};
