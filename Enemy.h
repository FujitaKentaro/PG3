#pragma once
#include <stdio.h>
#include <stdlib.h>

class Enemy
{
public:

	Enemy();
	// ������
	void Initialize();
	// �A�b�v�f�[�g
	void Update();

	// ��Ԋ֐�
	void Approach();
	void Attack();
	void Secession();

public:
	// �ÓI�����o
	static void (Enemy::* pFunc[])();

private:
	int phaseNum = 0;
};