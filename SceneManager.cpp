#include "SceneManager.h"
#include <stdio.h>

SceneManager::SceneManager() {}

SceneManager::~SceneManager() {}


SceneManager* SceneManager::GetInstance()
{
	// ŠÖ”“àstatic•Ï”‚Æ‚µ‚ÄéŒ¾‚·‚é
	static SceneManager instance;

	return &instance;
}

void SceneManager::ChangeScene(int num)
{
	switch (num)
	{
	case 0:

		printf("SceneNo:0\n");
		printf("\n TITLE \n\n");

		break;
	case 1:

		printf("SceneNo:1\n");
		printf("\n GAME SCENE 1 \n");

		break;
	case 2:

		printf("SceneNo:2\n");
		printf("\n GAME SCENE 2 \n");

		break;
	case 3:

		printf("SceneNo:3\n");
		printf("\n GAME CLEAR \n");

		break;
	default:
		break;
	}
}