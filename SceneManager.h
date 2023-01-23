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

	// コピーコンストラクタを無効にする
	SceneManager(const SceneManager&) = delete;
	// 代入演算子を無効にする
	SceneManager& operator=(const SceneManager&) = delete;

	// シーン変更関数
	void ChangeScene(int num);
};