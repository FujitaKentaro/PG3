#include <stdio.h>

int RecursivePay(int time) {
	if (time <= 1) {
		return 100;
	}

	return (RecursivePay(time - 1) * 2 - 50);
}

int RecursiveResult(int time) {
	int result = 0;
	for (int i = 1; i <= time; i++) {
		result += RecursivePay(i);
	}
	return result;
}
int GeneralPay(int time) {
	if (time <= 0) {
		return 0;
	}
	return 1072 * time;
}

int main() {
	int time = 1;
	while (true)
	{
		if (RecursiveResult(time) > GeneralPay(time)) {
			printf("\n %d 時間働くと %d円で 再帰的 の勝ち\n", time, RecursiveResult(time));
			break;
		}
		time++;
	}

	return 0;
}