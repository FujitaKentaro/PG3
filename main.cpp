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

	//�v�f�̑���̑���ԍ�
	int menuNum = 0;

	//�v�f�̕\���̑���ԍ�
	int selectNum = 0;


	while (true)
	{
		std::cout << "[�v�f�̑���]\n";
		std::cout << "1.�v�f�̕\��\n" ;
		std::cout << "2.�v�f�̑}��\n" ;

		if (lst.Size() > 0)
		{
			std::cout << "3.�v�f�̕ҏW\n";
			std::cout << "4.�v�f�̍폜\n";
		}
		std::cout << "----------------------------------\n";
		std::cout << "�����I�����Ă�������\n";

		if (menuNum == 0)
		{
			//����ԍ����擾
			scanf_s("%d", &menuNum);
		}
		system("cls");

		switch (menuNum)
		{
		case 1://�v�f�̕\��
			Display(lst, menuNum, selectNum);
			break;

		case 2://�Ō���ɗv�f��ǉ�
			Insert(lst, menuNum);
			break;

		case 3://�C�ӂ̏ꏊ�̒l��ύX
			Edit(lst, menuNum);
			break;
		case 4://�C�ӂ̏ꏊ�̍폜
			Delete(lst, menuNum);
			break;
		}
	}

	return 0;
}

template <typename Type>
void Display(TwowayList<Type>& list, int& operationNum, int& displayOperationNum) {
	std::cout << "[�v�f�̕\��]\n";
	std::cout << "1.�v�f�̈ꗗ�\��\n";
	std::cout << "2.���Ԃ��w�肵�ėv�f��\��\n";
	std::cout << "9.�v�f����ɖ߂�\n";
	std::cout << std::endl;
	std::cout << "�����I�����Ă�������" << std::endl;

	//����ԍ����擾
	std::cin >> displayOperationNum;
	system("cls");

	switch (displayOperationNum) {
	case 1:
		std::cout << "[�v�f�̈ꗗ�\��]" << std::endl;

		//�ꗗ�\��
		list.Dump();

		std::cout << "�v�f��:" << list.Size() << std::endl;

		break;
	case 2:
		std::cout << "[���Ԃ��w�肵�ėv�f��\��]" << std::endl;
		std::cout << "�\���������v�f�̏��Ԃ��w�肵�Ă��������B" << std::endl;

		//�w�肷��ԍ����擾
		int specifyNum;
		std::cin >> specifyNum;
		std::cout << std::endl;


		//�w�肵�ĕ\��
		list.ElementSpecification(specifyNum);

		break;

	case 9:
		operationNum = 0;
		break;
	}

	//�v�f����ɖ߂�Ȃ�������
	if (displayOperationNum == 1 || displayOperationNum == 2)
	{
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "1.�v�f�̕\���ɖ߂�" << std::endl;
		std::cout << "2.�v�f�̑���ɖ߂�" << std::endl;

		//����ԍ����擾
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
	std::cout << "[���X�g�v�f�̑}��]" << std::endl;
	std::cout << std::endl;
	std::cout << "�v�f��ǉ��ꏊ���w�肵�Ă��������B�Ō���ɒǉ�����ꍇ�͉������͂��Ȃ��ł��������B" << std::endl;

	std::string insertNum;
	while (std::getchar() != '\n');

	std::getline(std::cin, insertNum);

	if (insertNum == "")
	{
		std::cout << "�ǉ�����v�f�̒l����͂��Ă�������" << std::endl;
		int element;

		std::cin >> element;

		list.PushBack(element);

		std::cout << "�v�f" << element << "��" << "�Ō���ɑ}������܂���" << std::endl;
	}
	else
	{
		int index = std::atoi(insertNum.c_str());

		std::cout << "�ǉ�����v�f�̒l����͂��Ă�������" << std::endl;
		int element;

		std::cin >> element;

		list.Insert(element, index);

		std::cout << "�v�f" << element << "��" << index << "�Ԗڂɑ}������܂���" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.�v�f����ɖ߂�" << std::endl;

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
	std::cout << "[�v�f�̕ҏW]" << std::endl;
	std::cout << std::endl;
	std::cout << "�ҏW�������v�f�̔ԍ�����͂��Ă�������" << std::endl;

	int elementNum;
	std::cin >> elementNum;
	std::cout << std::endl;

	if (list.Search(elementNum))
	{
		std::cout << elementNum << "�Ԗڂ̗v�f�̕ύX����l����͂��Ă��������B" << std::endl;

		int changeElement{};
		std::cin >> changeElement;

		list.ChangeValue(changeElement, elementNum);
		std::cout << std::endl;

		std::cout << elementNum << "�Ԗڂ̗v�f�̒l��" << '"' << changeElement << '"' << "�ɕύX����܂���" << std::endl;
	}
	else
	{
		std::cout << elementNum << "�Ԗڂ̗v�f�̂�������܂���ł����B" << std::endl;
	}


	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.�v�f����ɖ߂�" << std::endl;

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
	std::cout << "[�v�f�̍폜]" << std::endl;
	std::cout << std::endl;
	std::cout << "�폜�������v�f�̔ԍ����w�肵�Ă�������" << std::endl;

	int elementNum;
	std::cin >> elementNum;
	std::cout << std::endl;

	if (list.Search(elementNum))
	{
		std::cout << elementNum << "�Ԗڂ̗v�f" << '"' << list.GetCell(elementNum) << '"' << "�폜���܂���" << std::endl;

		list.Delete(elementNum);

		std::cout << std::endl;
	}
	else
	{
		std::cout << elementNum << "�Ԗڂ̗v�f�̂�������܂���ł����B" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.�v�f����ɖ߂�" << std::endl;

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
