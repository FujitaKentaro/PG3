#include "Rectangle.h"
#include <stdio.h>

Rectangle::Rectangle() {
	height = 10;
	width = 10;
	result = 0;
}
Rectangle::Rectangle(float hei, float wid) {
	height = hei;
	width = wid;
	result = 0;
}
Rectangle::~Rectangle() {

}

void Rectangle::size() {
	result = height * width;
}
void Rectangle::draw() {
	printf("‹éŒ`‚ÌŒvZŒ‹‰ÊF%f\n", result);
}