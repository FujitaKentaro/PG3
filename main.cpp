#include <stdio.h>
#include <stdlib.h>
// �菇1 �P�������X�g�̍\���̂̒�`
typedef struct CELL {
	int val;
	struct CELL* next;
} CELL;

void create(CELL* cell,int val);	// �f�[�^��ǉ�����֐��̃v���g�^�C�v�錾
void index(CELL* cell);	// �ꗗ��\������֐��̃v���g�^�C�v�錾


int main() {
	int val;
	// 2 �擪�̃Z���̐錾
	CELL head;
	head.next = nullptr;	// ���B�W���A���X�^�W�I�ł�NEXT�ɉ��炩�̒l����������Ԃŏ����������̂ŁAnull�|�C���^�[��������
	while (true){
		scanf_s("%d", &val);

		// 3 �Ō���ɃZ����ǉ�
		create(&head, val);

		// 4 ���X�g�ꗗ�̕\��
		index(&head);
	}

	system("pause");

	return 0;
}

void create(CELL* cell, int val) {
	CELL* newCell;
	// �V�K�쐬����Z�����̃��������m�ۂ���
	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->val = val;
	newCell->next = nullptr;

	// �Ō�i�ŐV�j�̃Z���̃A�h���X�̈�ڂ̏����͈������玝���Ă���
	// ���X�g�̂����ŏ��̃Z���̃A�h���X���Y������
	while ()
	{

	}
}
void index(CELL* cell) {

}