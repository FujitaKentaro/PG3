#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �菇1 �P�������X�g�̍\���̂̒�`
typedef struct CELL {
	int val;
	struct CELL* prev;
	struct CELL* next;
} CELL;

void create(CELL* cell,int val);	// �f�[�^��ǉ�����֐��̃v���g�^�C�v�錾
void index(CELL* cell);	// �ꗗ��\������֐��̃v���g�^�C�v�錾
CELL* getInsertCellAddress(CELL* endCELL,int iterator);


int main() {
	int iterator;
	int inpitValue;
	CELL* insertCell;

	// 2 �擪�̃Z���̐錾
	CELL head;
	head.next = nullptr;	// ���B�W���A���X�^�W�I�ł�NEXT�ɉ��炩�̒l����������Ԃŏ����������̂ŁAnull�|�C���^�[��������
	while (true){
		printf("���Ԗڂ̃Z���̌��ɑ}�����܂����H\n");
		scanf_s("%d",&iterator);

		printf("�}������l����͂��Ă�������\n");
		scanf_s("%d", &inpitValue);

		// 3 �C�ӂ̃Z���̂�����ɒǉ�
		insertCell = getInsertCellAddress(&head,iterator);
		create(insertCell, inpitValue);

		// 4 ���X�g�ꗗ�̕\��
		index(&head);
	}

	system("pause");

	return 0;
}

void create(CELL* cell,int val) {
	CELL* newCell;
	// �V�K�쐬����Z�����̃��������m�ۂ���
	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->val = val;
	newCell->prev = cell;
	newCell->next = cell->next;

	if (cell->next) {
		CELL* nextCell = cell->next;
		nextCell->prev = newCell;
	}
	cell->next= newCell;
}

void index(CELL* endCell) {
	int no = 1;
	while (endCell->next!=nullptr)
	{
		endCell = endCell->next;
		printf("%d:no\n", no);
		printf(" %p\n", endCell->prev);
		printf(" %5d\n", endCell->val);
		printf(" (%p)\n", endCell);
		printf(" %p\n", endCell->next);
		no++;
	}
}

CELL* getInsertCellAddress(CELL* endCELL, int iterator) {
	for (int i = 0; i < iterator; i++) {
		if (endCELL->next) {
			endCELL = endCELL->next;
		}
		else
		{
			break;
		}
	}
	return endCELL;
}