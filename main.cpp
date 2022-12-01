#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 手順1 単方向リストの構造体の定義
typedef struct CELL {
	char str[30];
	struct CELL* next;
} CELL;

void create(CELL* cell,const char* buf);	// データを追加する関数のプロトタイプ宣言
void index(CELL* cell);	// 一覧を表示する関数のプロトタイプ宣言


int main() {
	char str[30];
	// 2 先頭のセルの宣言
	CELL head;
	head.next = nullptr;	// ヴィジュアルスタジオではNEXTに何らかの値が入った状態で初期化されるので、nullポインターを代入する
	while (true){
		scanf_s("%s", str,30);

		// 3 最後尾にセルを追加
		create(&head, str);

		// 4 リスト一覧の表示
		index(&head);
	}

	system("pause");

	return 0;
}

void create(CELL* cell,const char* buf) {
	CELL* newCell;
	// 新規作成するセル分のメモリを確保する
	newCell = (CELL*)malloc(sizeof(CELL));
	strcpy_s(newCell->str, 30, buf);
	newCell->next = nullptr;

	// 最後（最新）のセルのアドレスの一つ目の処理は引数から持ってきた
	// リストのうち最初のセルのアドレスが該当する
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