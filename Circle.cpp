#include "Circle.h"
#include <stdio.h>

Circle::Circle() {
	R = 5;
	result = 0;

}
Circle::Circle(float R) {
	this->R = R;
}
Circle::~Circle() {

}

void Circle::size() {
	result=(R* R)* PI;
}
void Circle::draw() {
	printf("�~�̌v�Z���ʁF%f\n", result);
}