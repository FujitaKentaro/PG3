#pragma once
#include "IShape.h"

class Rectangle :
    public IShape
{
public:
    Rectangle();
    Rectangle(float hei,float wid);
    ~Rectangle()override;
    void size() override;
    void draw() override;

private:
    float height;
    float width;

    float result;

};

