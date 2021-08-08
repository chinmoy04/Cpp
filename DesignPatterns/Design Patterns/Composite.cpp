#include<iostream>
#include<string>
#include<vector>

class Graphic
{
public:
    virtual void Draw() = 0;
    virtual void add(Graphic* ele)
    {
        std::cout << "Error" << std::endl;
    }
};

class Line : public Graphic
{
public:
    void Draw()
    {
        std::cout << "Inside Line" << std::endl;
    }
};

class Text : public Graphic
{
public:
    void Draw()
    {
        std::cout << "Inside Text" << std::endl;
    }
};

class Picture : public Graphic
{
    std::vector<Graphic*> containerVec;
public:
    void add(Graphic *ele)
    {
        containerVec.push_back(ele);
    }

    void Draw()
    {
        for(unsigned int i=0; i < containerVec.size(); i++)
        {
            containerVec[i]->Draw();
        }
    }
};

int main1()
{
    Picture p1;

    for(unsigned int i=0; i<4; i++)
    {
        p1.add(new Line());
    }

    for(unsigned int i=0; i<4; i++)
    {
        p1.add(new Text());
    }

    p1.add(new Picture());

    p1.Draw();

    getchar();

    return 0;
}
