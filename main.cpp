#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <functional>

typedef void (*PFunc)(int*);

// 関数
void isCorrect(int* num);
void SetTimeout(int second);

// ユーザー関係
void SetPlayerNum(int* num);

int main(int argc ,const char *argv[]) {

	int num=10;
	std::function<int(int)> fx = [=](int i) {return i + 1; };

	auto fx2 = [=](int i) {return i + 1; };

	printf("%d\n", fx(num));
	printf("%d\n", fx2(2));

	//[]() { printf("lamda test"); }();

	//srand(time(nullptr));

	//SetTimeout(3000); // 3000ミリ秒？

	return 0;
}

// 関数定義
void isCorrect(int* num) {
	int result;
	result = rand() % 12 + 1;
	// ランダムな値を返す
	printf(" 出目：%d\n", result);

	if (result % 2 == 0 && *num % 2 == 0 ||
		result % 2 == 1 && *num % 2 == 1) {
		printf("\n 正解 \n");
	}
	else {
		printf("\n 不正解 \n");
	}
}

void SetTimeout(int second) {
	PFunc p;
	int num;
	p = SetPlayerNum;
	p(&num);
	// 待機時間
	Sleep(second);
	// コールバック関数
	p = isCorrect;
	p(&num);
}

// 数の入力
void SetPlayerNum(int* num) {

	printf("値を入力してください\n\n");
	scanf_s("%d", num);
	if (*num % 2 == 0) {
		printf("偶数が入力されました\n");
		*num = 2;
	}
	else if (*num % 2 == 1) {
		printf("奇数が入力されました\n");
		*num = 1;
	}
	else {
		printf("予期せぬ値が入力されました\n");
	}
}