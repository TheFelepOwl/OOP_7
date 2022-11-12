#include <iostream>
#include<math.h>

using namespace std;

class Geometric_body
{

public:
    float  R, pi = 3.14159265359;
    virtual void Square() = 0;

    Geometric_body(float R)
    {
        this->R = R;
    }


};

class Ball : public Geometric_body
{

public:

    Ball(float R) : Geometric_body(R)
    {

    }

    void  Square() override
    {
        cout << (4.0 / 3.0) * pi * pow(R, 3);
    }
};

class Truncated : public Geometric_body
{

private:
    float r, h;

public:

    Truncated(float h, float r, float R) : Geometric_body(R)
    {
        this->h = h;
        this->r = r;
    }

    void  Square() override
    {

        cout << (1.0 / 3.0) * pi * h * (pow(R, 2) + R * r + pow(r, 2));

    }

};

class Cone : public Geometric_body
{
private:
    float h;

public:


    Cone(float h, float R) : Geometric_body(R)
    {
        this->h = h;
    }



    void  Square() override
    {

        cout << (1.0 / 3.0) * pi * pow(R, 2) * h;
    }
};

class Calculation
{
public:
    void Square(Geometric_body* geometric_body)
    {
        geometric_body->Square();
    }
};


int main()
{

    Ball a(5);
    Truncated b(5, 4, 3);
    Cone c(5, 4);

    Calculation calculation;

    cout << "Ball: ";
    calculation.Square(&a);

    cout << "\nTruncated: ";
    calculation.Square(&b);

    cout << "\nCone: ";
    calculation.Square(&c);












    return 0;
}