#include "Circle.h"
#include "Rectangle.h"
#include "IShape.h"

#include <time.h>
#include <stdlib.h>

int main() {

	srand(time(nullptr));
	int Rand = rand() % 12 + 1;

	// サイズ決め
	const int size = 2;
	IShape* ishape[] =
	{
		new Circle(Rand),
		new Rectangle(Rand,Rand)
	};
	
	for (int i = 0; i < size; i++)
	{
		// 計算
		ishape[i]->size();
		// 描画
		ishape[i]->draw();
	}

	// デストラクタ
	for (int i = 0; i < size; i++)
	{
		ishape[i]->~IShape();
	}

	return 0;
}