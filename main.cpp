#include <stdio.h>
#include <stdlib.h>
// 手順1 単方向リストの構造体の定義
typedef struct CELL {
	int val;
	struct CELL* next;
} CELL;

void create(CELL* cell,int val);	// データを追加する関数のプロトタイプ宣言
void index(CELL* cell);	// 一覧を表示する関数のプロトタイプ宣言


int main() {
	int val;
	// 2 先頭のセルの宣言
	CELL head;
	head.next = nullptr;	// ヴィジュアルスタジオではNEXTに何らかの値が入った状態で初期化されるので、nullポインターを代入する
	while (true){
		scanf_s("%d", &val);

		// 3 最後尾にセルを追加
		create(&head, val);

		// 4 リスト一覧の表示
		index(&head);
	}

	system("pause");

	return 0;
}

void create(CELL* cell, int val) {
	CELL* newCell;
	// 新規作成するセル分のメモリを確保する
	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->val = val;
	newCell->next = nullptr;

	// 最後（最新）のセルのアドレスの一つ目の処理は引数から持ってきた
	// リストのうち最初のセルのアドレスが該当する
	while ()
	{

	}
}
void index(CELL* cell) {

}