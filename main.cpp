#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "Enemy.h"


int main() {

	Enemy* enemy = new Enemy;

	enemy->Initialize();

	while (true) {

		enemy->Update();
		
		// Œ‹‰Ê‚ðŒ©‚â‚·‚­‚·‚é‚½‚ß
		Sleep(1 * 1000);
		system("cls");
	}

	delete enemy;

	system("pause");
	return 0;

}

