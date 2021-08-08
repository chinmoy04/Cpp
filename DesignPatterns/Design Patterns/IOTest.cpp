class Sensor
{

};

class SensorX
{

public:
    void open();
    void getVal();
    void close();

};

class IOT
{
    SensorX &s;
public:

    void setSensor(const SensorX& s1)
    {
        s = s1;
    }
};

