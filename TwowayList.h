#include <iostream>
#include <string>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//using namespace std;

template <typename T>
struct Cell
{   // 値
	T val_;
	// 前のセルのポインタ
	Cell* prev_;
	// 次のセルのポインタ
	Cell* next_;
	// コンストラクタ
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
	//ダミー
	Cell<T>* dummy_;

	int size_;

	//セルが指した後ろに追加
	void Add(T v, Cell<T>* node)
	{
		//新しいセルを生成
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
	/// 任意の場所に追加
	/// </summary>
	/// <param name="value_">値</param>
	/// <param name="num">追加する場所(0~)</param>
	void Insert(T value_, int num)
	{
		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy_;

		//任意の場所まで移動
		for (int i = 0; i < num; i++)
		{
			tmpCell = tmpCell->next_;
		}

		//追加
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

		//任意の場所まで移動
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
	/// 任意の場所の値を変更
	/// </summary>
	/// <param name="value_">値</param>
	/// <param name="num">変更する場所(0~)</param>
	bool ChangeValue(T value_, int num)
	{

		if (num < 0 || num>size_)
		{
			return false;
		}

		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy_;

		//任意の場所まで移動
		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next_;
		}

		//変更
		tmpCell->val_ = value_;

		return true;

	}

	/// <summary>
	/// 一覧表示
	/// </summary>
	void Dump()
	{
		Cell<T>* ptr = dummy_->next_;

		std::cout << "要素一覧:{" << std::endl;

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

		//任意の場所まで移動
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
