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

	printf("�l����͂��Ă�������\n\n");
	scanf_s(" %d", &num);
	if (num % 2 == 0) {
		printf("���������͂���܂���\n");
		num = 2;
	}
	else if (num % 2 == 1) {
		printf("������͂���܂���\n");
		num = 1;
	}
	else {
		printf("�\�����ʒl�����͂���܂���\n");
	}


	// �����_��
	std::function<void()> PlayerNum = [=]() {
		int result;
		result = rand() % 12 + 1;
		// �����_���Ȓl��Ԃ�
		printf(" �o�ځF%d\n", result);
		if (result % 2 == 0 && num % 2 == 0 ||
			result % 2 == 1 && num % 2 == 1) {
			printf("\n ���� \n");
		}
		else {
			printf("\n �s���� \n");
		}
	};
	std::function<void(std::function<void()>, int)>setTimeout = [=](std::function<void()> plNum, int num) {
		Sleep(num * 1000);
		plNum();
	};
	//std::function<void(int*, std::function<void(int*)>)> SetTimeOut = [](int* num, std::function<void(int*)> PlNum) {

	//	// �ҋ@����
	//	Sleep(3 * 1000);

	//	PlNum(num);
	//};
	

	// ���s
	setTimeout(PlayerNum,num);

	system("pause");

	return 0;
}
