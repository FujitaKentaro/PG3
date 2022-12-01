#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 手順1 単方向リストの構造体の定義
typedef struct CELL {
	int val;
	struct CELL* prev;
	struct CELL* next;
} CELL;

void create(CELL* cell,int val);	// データを追加する関数のプロトタイプ宣言
void index(CELL* cell);	// 一覧を表示する関数のプロトタイプ宣言
CELL* getInsertCellAddress(CELL* endCELL,int iterator);


int main() {
	int iterator;
	int inpitValue;
	CELL* insertCell;

	// 2 先頭のセルの宣言
	CELL head;
	head.next = nullptr;	// ヴィジュアルスタジオではNEXTに何らかの値が入った状態で初期化されるので、nullポインターを代入する
	while (true){
		printf("何番目のセルの後ろに挿入しますか？\n");
		scanf_s("%d",&iterator);

		printf("挿入する値を入力してください\n");
		scanf_s("%d", &inpitValue);

		// 3 任意のセルのうしろに追加
		insertCell = getInsertCellAddress(&head,iterator);
		create(insertCell, inpitValue);

		// 4 リスト一覧の表示
		index(&head);
	}

	system("pause");

	return 0;
}

void create(CELL* cell,int val) {
	CELL* newCell;
	// 新規作成するセル分のメモリを確保する
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