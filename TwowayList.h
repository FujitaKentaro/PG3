#include <iostream>
#include <string>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//using namespace std;

template <typename T>
struct Cell
{   // �l
	T val_;
	// �O�̃Z���̃|�C���^
	Cell* prev_;
	// ���̃Z���̃|�C���^
	Cell* next_;
	// �R���X�g���N�^
	Cell()
	{
		prev_ = this;
		next_ = this;
	}
	Cell(T value, Cell* prev, Cell* next)
	{
		val_ = value;
		prev_ = prev;
		next_ = next;
	}
};

template <typename T>
class TwowayList
{
private:
	//�_�~�[
	Cell<T>* dummy_;

	int size_;

	//�Z�����w�������ɒǉ�
	void Add(T v, Cell<T>* node)
	{
		//�V�����Z���𐶐�
		Cell<T>* newNode = new Cell<T>(v, node, node->next_);
		node->next_->prev_ = newNode;
		node->next_ = newNode;
		node = newNode;
		size_++;
	}


public:
	TwowayList()
	{
		dummy_ = new Cell<T>();
		size_ = 0;
	}
	~TwowayList()
	{
		//Clear();
	}


	void PushFront(T value)
	{
		Cell<T>* cur = dummy_;
		Add(value, cur);
	}
	void PushBack(T value)
	{
		Cell<T>* cur = dummy_->prev_;
		Add(value, cur);
	}

	/// <summary>
	/// �C�ӂ̏ꏊ�ɒǉ�
	/// </summary>
	/// <param name="value_">�l</param>
	/// <param name="num">�ǉ�����ꏊ(0~)</param>
	void Insert(T value_, int num)
	{
		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy_;

		//�C�ӂ̏ꏊ�܂ňړ�
		for (int i = 0; i < num; i++)
		{
			tmpCell = tmpCell->next_;
		}

		//�ǉ�
		Add(value_, tmpCell);
	}

	void ElementSpecification(int num) {
		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy_;

		int index = -1;

		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next_;
			index++;
		}

		std::cout << index << ':' << tmpCell->val_ << '\n';
	}

	Cell<T>* GetCell(int num)
	{
		Cell<T>* tmpCell = dummy_;

		//�C�ӂ̏ꏊ�܂ňړ�
		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next_;
		}

		return tmpCell;
	}

	//
	bool Search(int num)
	{
		if (num < 0 || num>size_)
		{
			return false;
		}

		return true;
	}

	/// <summary>
	/// �C�ӂ̏ꏊ�̒l��ύX
	/// </summary>
	/// <param name="value_">�l</param>
	/// <param name="num">�ύX����ꏊ(0~)</param>
	bool ChangeValue(T value_, int num)
	{

		if (num < 0 || num>size_)
		{
			return false;
		}

		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy_;

		//�C�ӂ̏ꏊ�܂ňړ�
		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next_;
		}

		//�ύX
		tmpCell->val_ = value_;

		return true;

	}

	/// <summary>
	/// �ꗗ�\��
	/// </summary>
	void Dump()
	{
		Cell<T>* ptr = dummy_->next_;

		std::cout << "�v�f�ꗗ:{" << std::endl;

		int index = 0;
		for (int i = 0; i < size_ - 1; i++)
		{
			std::cout << ' ' << index << ':' << '"' << ptr->val_ << '"' << ',' << std::endl;
			ptr = ptr->next_;
			index++;
		}
		std::cout << ' ' << index << ':' << '"' << ptr->val_ << '"' << std::endl;

		std::cout << '}' << std::endl;
	}

	int Size()
	{
		return size_;
	}
	bool Delete(int num)
	{
		if (num < 0 || num>size_)
		{
			return false;
		}

		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy_;

		//�C�ӂ̏ꏊ�܂ňړ�
		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next_;
		}

		tmpCell->prev_->next_ = tmpCell->next_;
		tmpCell->next_->prev_ = tmpCell->next_;

		delete tmpCell;

		size_--;

		return true;
	}
};
