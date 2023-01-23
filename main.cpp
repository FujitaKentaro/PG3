#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <functional>

using namespace std;

int main(int argc, const char* argv[]) {

	srand(time(nullptr));

	int waitTime = 3;

	int num;

	printf("値を入力してください\n\n");
	scanf_s(" %d", &num);
	if (num % 2 == 0) {
		printf("偶数が入力されました\n");
		num = 2;
	}
	else if (num % 2 == 1) {
		printf("奇数が入力されました\n");
		num = 1;
	}
	else {
		printf("予期せぬ値が入力されました\n");
	}


	// ラムダ式
	std::function<void()> PlayerNum = [=]() {
		int result;
		result = rand() % 12 + 1;
		// ランダムな値を返す
		printf(" 出目：%d\n", result);
		if (result % 2 == 0 && num % 2 == 0 ||
			result % 2 == 1 && num % 2 == 1) {
			printf("\n 正解 \n");
		}
		else {
			printf("\n 不正解 \n");
		}
	};
	std::function<void(std::function<void()>, int)>setTimeout = [=](std::function<void()> plNum, int num) {
		Sleep(num * 1000);
		plNum();
	};
	//std::function<void(int*, std::function<void(int*)>)> SetTimeOut = [](int* num, std::function<void(int*)> PlNum) {

	//	// 待機時間
	//	Sleep(3 * 1000);

	//	PlNum(num);
	//};
	

	// 実行
	setTimeout(PlayerNum,num);

	system("pause");

	return 0;
}
