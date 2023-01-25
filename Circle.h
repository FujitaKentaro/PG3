#pragma once
#include "IShape.h"

class Circle :
    public IShape
{
public:
    Circle();
    Circle(float R);
    ~Circle()override;
    void size() override;
    void draw() override;

private:
    float R;
    const float PI = 3.14159265;

    float result;
};

