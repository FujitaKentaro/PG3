#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <functional>

typedef void (*PFunc)(int*);

// �֐�
void isCorrect(int* num);
void SetTimeout(int second);

// ���[�U�[�֌W
void SetPlayerNum(int* num);

int main(int argc ,const char *argv[]) {

	int num=10;
	std::function<int(int)> fx = [=](int i) {return i + 1; };

	auto fx2 = [=](int i) {return i + 1; };

	printf("%d\n", fx(num));
	printf("%d\n", fx2(2));

	//[]() { printf("lamda test"); }();

	//srand(time(nullptr));

	//SetTimeout(3000); // 3000�~���b�H

	return 0;
}

// �֐���`
void isCorrect(int* num) {
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
}

void SetTimeout(int second) {
	PFunc p;
	int num;
	p = SetPlayerNum;
	p(&num);
	// �ҋ@����
	Sleep(second);
	// �R�[���o�b�N�֐�
	p = isCorrect;
	p(&num);
}

// ���̓���
void SetPlayerNum(int* num) {

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
}