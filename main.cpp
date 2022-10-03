#include <stdio.h>

int RecursivePay(int time,int wage) {
	if (time <= 1) {
		return wage;
	}
	wage = wage + (wage * 2 - 50);
	return RecursivePay(time - 1, wage);
}

int main() {

	int timeLimits = 8; // 8����

	// ����
	const int nomalWage = 1072;
	int recWage = 100;

	// �҂����z �i�[�ϐ�
	int depositNomal = 0;
	int depositRec = 0;


	for (int i = 0; i < timeLimits; i++) {
		depositNomal += nomalWage;
	}
	depositRec = RecursivePay(timeLimits, recWage);
	
	printf("�ċA�I : %d\n", depositRec);
	printf("��ʓI : %d\n", depositNomal);
	

	return 0;
}