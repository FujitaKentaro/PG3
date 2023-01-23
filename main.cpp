#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "SceneManager.h"

int main() {

	SceneManager* sceneManager = SceneManager::GetInstance();
	int num = 0;

	while (true) {

		sceneManager->ChangeScene(num);

		if (num >= 4) {

			system("cls");
			num = 0;
		}
		else {

			num++;
		}

		Sleep(1 * 1000);
	}

	system("pause");
	return 0;

}