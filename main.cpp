#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "Enemy.h"


int main() {



	Enemy* enemy = new Enemy;
	Enemy* enemy2 = new Enemy;
	Enemy* enemy3 = new Enemy;


	int isDead = 0;

	enemy->Initialize();
	enemy2->Initialize();
	enemy3->Initialize();


	while (true) {

		
		printf("1:¶‚©‚·2:“|‚·\n");
		scanf_s("%d", &isDead);

		switch (isDead)
		{
		case 1:// 
			Enemy::isAlive = false;
			break;
		case 2:// Ž€‚Ê
			Enemy::isAlive = true;
			break;
		default:
			printf("1or2 ‚Å“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
			break;
		}

		if (isDead == 1 || isDead == 2) {
			enemy->Update();
			enemy2->Update();
			enemy3->Update();
		}
		// Œ‹‰Ê‚ðŒ©‚â‚·‚­‚·‚é‚½‚ß
		Sleep(5 * 1000);
		system("cls");
	}

	delete enemy;
	delete enemy2;
	delete enemy3;

	system("pause");
	return 0;

}

