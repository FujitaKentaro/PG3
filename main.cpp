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

	lst.PushBack("5");
	lst.PushBack("4");
	lst.PushBack("3");
	lst.PushBack("2");
	lst.PushBack("1");

	lst.Dump();

	//—v‘f‚Ì‘€ì‚Ì‘€ì”Ô†
	int menuNum = 0;

	//—v‘f‚Ì•\¦‚Ì‘€ì”Ô†
	int selectNum = 0;


	while (true)
	{
		std::cout << "[—v‘f‚Ì‘€ì]\n";
		std::cout << "1.—v‘f‚Ì•\¦\n" ;
		std::cout << "2.—v‘f‚Ì‘}“ü\n" ;

		if (lst.Size() > 0)
		{
			std::cout << "3.—v‘f‚Ì•ÒW\n";
			std::cout << "4.—v‘f‚Ìíœ\n";
		}
		std::cout << "----------------------------------\n";
		std::cout << "‘€ì‚ğ‘I‘ğ‚µ‚Ä‚­‚¾‚³‚¢\n";

		if (menuNum == 0)
		{
			//‘€ì”Ô†‚ğæ“¾
			scanf_s("%d", &menuNum);
		}
		system("cls");

		switch (menuNum)
		{
		case 1://—v‘f‚Ì•\¦
			Display(lst, menuNum, selectNum);
			break;

		case 2://ÅŒã”ö‚É—v‘f‚ğ’Ç‰Á
			Insert(lst, menuNum);
			break;

		case 3://”CˆÓ‚ÌêŠ‚Ì’l‚ğ•ÏX
			Edit(lst, menuNum);
			break;
		case 4://”CˆÓ‚ÌêŠ‚Ìíœ
			Delete(lst, menuNum);
			break;
		}
	}

	return 0;
}

template <typename Type>
void Display(TwowayList<Type>& list, int& operationNum, int& displayOperationNum) {
	std::cout << "[—v‘f‚Ì•\¦]\n";
	std::cout << "1.—v‘f‚Ìˆê——•\¦\n";
	std::cout << "2.‡”Ô‚ğw’è‚µ‚Ä—v‘f‚ğ•\¦\n";
	std::cout << "9.—v‘f‘€ì‚É–ß‚é\n";
	std::cout << std::endl;
	std::cout << "‘€ì‚ğ‘I‘ğ‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;

	//‘€ì”Ô†‚ğæ“¾
	std::cin >> displayOperationNum;
	system("cls");

	switch (displayOperationNum) {
	case 1:
		std::cout << "[—v‘f‚Ìˆê——•\¦]" << std::endl;

		//ˆê——•\¦
		list.Dump();

		std::cout << "—v‘f”:" << list.Size() << std::endl;

		break;
	case 2:
		std::cout << "[‡”Ô‚ğw’è‚µ‚Ä—v‘f‚ğ•\¦]" << std::endl;
		std::cout << "•\¦‚µ‚½‚¢—v‘f‚Ì‡”Ô‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢B" << std::endl;

		//w’è‚·‚é”Ô†‚ğæ“¾
		int specifyNum;
		std::cin >> specifyNum;
		std::cout << std::endl;


		//w’è‚µ‚Ä•\¦
		list.ElementSpecification(specifyNum);

		break;

	case 9:
		operationNum = 0;
		break;
	}

	//—v‘f‘€ì‚É–ß‚ç‚È‚©‚Á‚½‚ç
	if (displayOperationNum == 1 || displayOperationNum == 2)
	{
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "1.—v‘f‚Ì•\¦‚É–ß‚é" << std::endl;
		std::cout << "2.—v‘f‚Ì‘€ì‚É–ß‚é" << std::endl;

		//‘€ì”Ô†‚ğæ“¾
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
	std::cout << "[ƒŠƒXƒg—v‘f‚Ì‘}“ü]" << std::endl;
	std::cout << std::endl;
	std::cout << "—v‘f‚ğ’Ç‰ÁêŠ‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢BÅŒã”ö‚É’Ç‰Á‚·‚éê‡‚Í‰½‚à“ü—Í‚µ‚È‚¢‚Å‚­‚¾‚³‚¢B" << std::endl;

	std::string insertNum;
	while (std::getchar() != '\n');

	std::getline(std::cin, insertNum);

	if (insertNum == "")
	{
		std::cout << "’Ç‰Á‚·‚é—v‘f‚Ì’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;
		int element;

		std::cin >> element;

		list.PushBack(element);

		std::cout << "—v‘f" << element << "‚ª" << "ÅŒã”ö‚É‘}“ü‚³‚ê‚Ü‚µ‚½" << std::endl;
	}
	else
	{
		int index = std::atoi(insertNum.c_str());

		std::cout << "’Ç‰Á‚·‚é—v‘f‚Ì’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;
		int element;

		std::cin >> element;

		list.Insert(element, index);

		std::cout << "—v‘f" << element << "‚ª" << index << "”Ô–Ú‚É‘}“ü‚³‚ê‚Ü‚µ‚½" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.—v‘f‘€ì‚É–ß‚é" << std::endl;

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
	std::cout << "[—v‘f‚Ì•ÒW]" << std::endl;
	std::cout << std::endl;
	std::cout << "•ÒW‚µ‚½‚¢—v‘f‚Ì”Ô†‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;

	int elementNum;
	std::cin >> elementNum;
	std::cout << std::endl;

	if (list.Search(elementNum))
	{
		std::cout << elementNum << "”Ô–Ú‚Ì—v‘f‚Ì•ÏX‚·‚é’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B" << std::endl;

		int changeElement{};
		std::cin >> changeElement;

		list.ChangeValue(changeElement, elementNum);
		std::cout << std::endl;

		std::cout << elementNum << "”Ô–Ú‚Ì—v‘f‚Ì’l‚ª" << '"' << changeElement << '"' << "‚É•ÏX‚³‚ê‚Ü‚µ‚½" << std::endl;
	}
	else
	{
		std::cout << elementNum << "”Ô–Ú‚Ì—v‘f‚Ì‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½B" << std::endl;
	}


	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.—v‘f‘€ì‚É–ß‚é" << std::endl;

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
	std::cout << "[—v‘f‚Ìíœ]" << std::endl;
	std::cout << std::endl;
	std::cout << "íœ‚µ‚½‚¢—v‘f‚Ì”Ô†‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;

	int elementNum;
	std::cin >> elementNum;
	std::cout << std::endl;

	if (list.Search(elementNum))
	{
		std::cout << elementNum << "”Ô–Ú‚Ì—v‘f" << '"' << list.GetCell(elementNum) << '"' << "íœ‚µ‚Ü‚µ‚½" << std::endl;

		list.Delete(elementNum);

		std::cout << std::endl;
	}
	else
	{
		std::cout << elementNum << "”Ô–Ú‚Ì—v‘f‚Ì‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½B" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.—v‘f‘€ì‚É–ß‚é" << std::endl;

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
