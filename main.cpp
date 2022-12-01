#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TwowayList.h"


template <typename Type>
void Display(TwowayList<Type>& list, int& select, int& menu);
template <typename Type>
void Insert(TwowayList<Type>& list, int& select);
template <typename Type>
void Edit(TwowayList<Type>& list, int& select);
template <typename Type>
void Delete(TwowayList<Type>& list, int& select);

int main()
{
	TwowayList<std::string> lst;

	//要素の操作の操作番号
	int menuNum = 0;

	//要素の表示の操作番号
	int selectNum = 0;


	while (true)
	{
		std::cout << "[要素の操作]\n";
		std::cout << "1.要素の表示\n" ;
		std::cout << "2.要素の挿入\n" ;

		if (lst.Size() > 0)
		{
			std::cout << "3.要素の編集\n";
			std::cout << "4.要素の削除\n";
		}
		std::cout << "----------------------------------\n";
		std::cout << "操作を選択してください\n";

		if (menuNum == 0)
		{
			//操作番号を取得
			scanf_s("%d", &menuNum);
		}
		system("cls");

		switch (menuNum)
		{
		case 1://要素の表示
			Display(lst, menuNum, selectNum);
			break;

		case 2://最後尾に要素を追加
			Insert(lst, menuNum);
			break;

		case 3://任意の場所の値を変更
			Edit(lst, menuNum);
			break;
		case 4://任意の場所の削除
			Delete(lst, menuNum);
			break;
		}
	}

	return 0;
}

template <typename Type>
void Display(TwowayList<Type>& list, int& operationNum, int& displayOperationNum) {
	std::cout << "[要素の表示]\n";
	std::cout << "1.要素の一覧表示\n";
	std::cout << "2.順番を指定して要素を表示\n";
	std::cout << "9.要素操作に戻る\n";
	std::cout << std::endl;
	std::cout << "操作を選択してください" << std::endl;

	//操作番号を取得
	std::cin >> displayOperationNum;
	system("cls");

	switch (displayOperationNum) {
	case 1:
		std::cout << "[要素の一覧表示]" << std::endl;

		//一覧表示
		list.Dump();

		std::cout << "要素数:" << list.Size() << std::endl;

		break;
	case 2:
		std::cout << "[順番を指定して要素を表示]" << std::endl;
		std::cout << "表示したい要素の順番を指定してください。" << std::endl;

		//指定する番号を取得
		int specifyNum;
		std::cin >> specifyNum;
		std::cout << std::endl;


		//指定して表示
		list.ElementSpecification(specifyNum);

		break;

	case 9:
		operationNum = 0;
		break;
	}

	//要素操作に戻らなかったら
	if (displayOperationNum == 1 || displayOperationNum == 2)
	{
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "1.要素の表示に戻る" << std::endl;
		std::cout << "2.要素の操作に戻る" << std::endl;

		//操作番号を取得
		std::cin >> displayOperationNum;

		system("cls");
		switch (displayOperationNum)
		{
		case 1:
			operationNum = 1;
			break;
		case 2:
			operationNum = 0;
			break;
		default:
			break;
		}
	}
}

template <typename Type>
void Insert(TwowayList<Type>& list, int& operationNum)
{
	std::cout << "[リスト要素の挿入]" << std::endl;
	std::cout << std::endl;
	std::cout << "要素を追加場所を指定してください。最後尾に追加する場合は何も入力しないでください。" << std::endl;

	std::string insertNum;
	while (std::getchar() != '\n');

	std::getline(std::cin, insertNum);

	if (insertNum == "")
	{
		std::cout << "追加する要素の値を入力してください" << std::endl;
		Type element{};

		std::cin >> element;

		list.PushBack(element);

		std::cout << "要素" << element << "が" << "最後尾に挿入されました" << std::endl;
	}
	else
	{
		int index = std::atoi(insertNum.c_str());

		std::cout << "追加する要素の値を入力してください" << std::endl;
		Type element{};

		std::cin >> element;

		list.Insert(element, index);

		std::cout << "要素" << element << "が" << index << "番目に挿入されました" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		operationNum = 0;
	}
	else
	{
		operationNum = 2;
	}
}

template <typename Type>
void Edit(TwowayList<Type>& list, int& operationNum)
{
	std::cout << "[要素の編集]" << std::endl;
	std::cout << std::endl;
	std::cout << "編集したい要素の番号を入力してください" << std::endl;

	int elementNum;
	std::cin >> elementNum;
	std::cout << std::endl;

	if (list.Search(elementNum))
	{
		std::cout << elementNum << "番目の要素の変更する値を入力してください。" << std::endl;

		Type changeElement{};
		std::cin >> changeElement;

		list.ChangeValue(changeElement, elementNum);
		std::cout << std::endl;

		std::cout << elementNum << "番目の要素の値が" << '"' << changeElement << '"' << "に変更されました" << std::endl;
	}
	else
	{
		std::cout << elementNum << "番目の要素のが見つかりませんでした。" << std::endl;
	}


	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		operationNum = 0;
	}
	else
	{
		operationNum = 3;
	}

}

template <typename Type>
void Delete(TwowayList<Type>& list, int& operationNum)
{
	std::cout << "[要素の削除]" << std::endl;
	std::cout << std::endl;
	std::cout << "削除したい要素の番号を指定してください" << std::endl;

	int elementNum;
	std::cin >> elementNum;
	std::cout << std::endl;

	if (list.Search(elementNum))
	{
		std::cout << elementNum << "番目の要素" << '"' << list.GetCell(elementNum) << '"' << "削除しました" << std::endl;

		list.Delete(elementNum);

		std::cout << std::endl;
	}
	else
	{
		std::cout << elementNum << "番目の要素のが見つかりませんでした。" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		operationNum = 0;
	}
	else
	{
		operationNum = 4;
	}
}
