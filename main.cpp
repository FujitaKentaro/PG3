#include <stdio.h>
#include <Windows.h>
#include "SceneManager.h"

int main() {

	SceneManager* sceneManager = SceneManager::GetInstance();
	int num = 0;

	while (true) {

		if (num == 3) {
			num = 0;
		}
		else if(num >= 4){

			break;
		}

		sceneManager->ChangeScene(num);

		num++;

		Sleep(1.5 * 1000);
	}

	system("pause");
	return 0;

}