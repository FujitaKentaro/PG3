#pragma once
#include <stdio.h>
#include <stdlib.h>

class Enemy
{
public:
	//�����o�֐�
	// ?������
	void Initialize();

	// ?�A�b�v�f�[�g
	void Update();

	// �`�揈��
	void Draw();

public:

	//�ÓI�����o�ϐ�
	static bool isAlive;
};