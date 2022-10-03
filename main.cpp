#include <stdio.h>

int RecursivePay(int time,int wage) {
	if (time <= 1) {
		return wage;
	}
	wage = wage + (wage * 2 - 50);
	return RecursivePay(time - 1, wage);
}

int main() {

	int timeLimits = 8; // 8ŽžŠÔ

	// Žž‹‹
	const int nomalWage = 1072;
	int recWage = 100;

	// ‰Ò‚¢‚¾Šz Ši”[•Ï”
	int depositNomal = 0;
	int depositRec = 0;


	for (int i = 0; i < timeLimits; i++) {
		depositNomal += nomalWage;
	}
	depositRec = RecursivePay(timeLimits, recWage);
	
	printf("Ä‹A“I : %d\n", depositRec);
	printf("ˆê”Ê“I : %d\n", depositNomal);
	

	return 0;
}