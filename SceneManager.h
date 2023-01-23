#pragma once
class SceneManager final
{
private:
	//コンストラクタをprivateにする
	SceneManager();
	//デストラクタをprivateにする
	~SceneManager();
public:
	// インスタンス
	static SceneManager* GetInstance();

public:
	// コピーコンストラクタを無効にする
	SceneManager(const SceneManager&) = delete;
	// 代入演算子を無効にする
	SceneManager& operator=(const SceneManager&) = delete;

	void ChangeScene(int sceneNo);

	void TitleScene();
	void NewGameScene();
	void GamePlayScene();
	void GameClear();

};