#include <stdio.h>
#include <Windows.h>
#include "SceneManager.h"

int main() {

	SceneManager* sceneManager = SceneManager::GetInstance();
	int num = 0;

	while (true) {

		if (num >= 4) {

			system("cls");
			num = 0;
		}

		sceneManager->ChangeScene(num);

		num++;

		Sleep(1 * 1000);
	}

	system("pause");
	return 0;

}