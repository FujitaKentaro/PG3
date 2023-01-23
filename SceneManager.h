#pragma once


class SceneManager final
{
private:
	//�R���X�g���N�^��private�ɂ���
	SceneManager();
	//�f�X�g���N�^��private�ɂ���
	~SceneManager();

public:
	// �C���X�^���X
	static SceneManager* GetInstance();

	// �R�s�[�R���X�g���N�^�𖳌��ɂ���
	SceneManager(const SceneManager&) = delete;
	// ������Z�q�𖳌��ɂ���
	SceneManager& operator=(const SceneManager&) = delete;

	// �V�[���ύX�֐�
	void ChangeScene(int num);
};