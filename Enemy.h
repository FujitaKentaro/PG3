#pragma once
#include <stdio.h>
#include <stdlib.h>

class Enemy
{
public:

	Enemy();
	// 初期化
	void Initialize();
	// アップデート
	void Update();

	// 状態関数
	void Approach();
	void Attack();
	void Secession();

public:
	// 静的メンバ
	static void (Enemy::* pFunc[])();

private:
	int phaseNum = 0;
};