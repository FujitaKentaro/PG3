#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <functional>

using namespace std;

// �֐�
void SetTimeout(int second, std::function<void(int*)> PlNum, std::function<void(int*)> Corect);

int main(int argc ,const char *argv[]) {

	srand(time(nullptr));

	int waitTime = 3;

	std::function<void(int*)> PlayerNum = [](int* num) {
		printf("�l����͂��Ă�������\n\n");
		scanf_s("%d", num);
		if (*num % 2 == 0) {
			printf("���������͂���܂���\n");
			*num = 2;
		}
		else if (*num % 2 == 1) {
			printf("������͂���܂���\n");
			*num = 1;
		}
		else {
			printf("�\�����ʒl�����͂���܂���\n");
		}
	};
	std::function<void(int*)> Correct = [](int* num) {
		int result;
		result = rand() % 12 + 1;
		// �����_���Ȓl��Ԃ�
		printf(" �o�ځF%d\n", result);
		if (result % 2 == 0 && *num % 2 == 0 ||
			result % 2 == 1 && *num % 2 == 1) {
			printf("\n ���� \n");
		}
		else {
			printf("\n �s���� \n");
		}		
	};

	SetTimeout(waitTime,PlayerNum,Correct); 

	return 0;
}

// �֐���`

void SetTimeout(int second, std::function<void(int*)> PlNum, std::function<void(int*)> Corect) {
	int num;
	PlNum(&num);
	// �ҋ@����
	Sleep(second * 1000);
	// �R�[���o�b�N�֐�
	Corect(&num);
}