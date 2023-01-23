#include "SceneManager.h"
#include <stdio.h>

SceneManager::SceneManager() {}

SceneManager::~SceneManager() {}


SceneManager* SceneManager::GetInstance()
{
	// 関数内static変数として宣言する
	static SceneManager instance;

	return &instance;
}

void SceneManager::ChangeScene(int sceneNo)
{
	switch (sceneNo)
	{
	case 0:
		TitleScene();
		break;
	case 1:
		NewGameScene();
		break;
	case 2:
		GamePlayScene();
		break;
	case 3:
		GameClear();
		break;
	default:
		break;
	}
}

void SceneManager::TitleScene() {
	printf("SceneNo:0\n");
	printf("\n TITLE \n\n");
}

void SceneManager::NewGameScene() {
	printf("SceneNo:1\n");
	printf("\n GAME SCENE 1 \n");
}

void SceneManager::GamePlayScene() {
	printf("SceneNo:2\n");
	printf("\n GAME SCENE 2 \n");
}

void SceneManager::GameClear() {
	printf("SceneNo:3\n");
	printf("\n GAME CLEAR \n");
}