#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

typedef void (*PFunc)(int*);

// 関数
void isCorrect(int* num);
void SetTimeout(int second, PFunc p);

// ユーザー関係
void SetPlayerNum(int* num);

int main(int argc ,char *argv[]) {

	srand(time(nullptr));

	PFunc p;
	p = SetPlayerNum;

	SetTimeout(3000,p); // 3000ミリ秒？

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

void SetTimeout(int second,PFunc pf) {
	PFunc p;
	int num;
	// 引数でもらった関数の実行
	pf(&num);

	// 待機時間
	Sleep(second);
	// 関数ポインタ
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