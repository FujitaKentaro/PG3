#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �菇1 �P�������X�g�̍\���̂̒�`
typedef struct CELL {
	char str[30];
	struct CELL* next;
} CELL;

void create(CELL* cell,const char* buf);	// �f�[�^��ǉ�����֐��̃v���g�^�C�v�錾
void index(CELL* cell);	// �ꗗ��\������֐��̃v���g�^�C�v�錾


int main() {
	char str[30];
	// 2 �擪�̃Z���̐錾
	CELL head;
	head.next = nullptr;	// ���B�W���A���X�^�W�I�ł�NEXT�ɉ��炩�̒l����������Ԃŏ����������̂ŁAnull�|�C���^�[��������
	while (true){
		scanf_s("%s", str,30);

		// 3 �Ō���ɃZ����ǉ�
		create(&head, str);

		// 4 ���X�g�ꗗ�̕\��
		index(&head);
	}

	system("pause");

	return 0;
}

void create(CELL* cell,const char* buf) {
	CELL* newCell;
	// �V�K�쐬����Z�����̃��������m�ۂ���
	newCell = (CELL*)malloc(sizeof(CELL));
	strcpy_s(newCell->str, 30, buf);
	newCell->next = nullptr;

	// �Ō�i�ŐV�j�̃Z���̃A�h���X�̈�ڂ̏����͈������玝���Ă���
	// ���X�g�̂����ŏ��̃Z���̃A�h���X���Y������
	while (cell->next!=nullptr)
	{
		cell = cell->next;
	}
	cell= newCell;
}
void index(CELL* cell) {
	while (cell->next!=nullptr)
	{
		printf("%s\n", cell->str);
	}
}