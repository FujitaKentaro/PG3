#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <functional>
#include <vector>

using namespace std;

int main() {

	vector<int> b = { 10,20,30 };

	b.push_back(40); // 追加
	b.pop_back();	// 削除
	{
		// 配列と全く同じや
		// float型の可変長配列 ｃ （要素数：3）
		vector<float> c = { 0.0f,1.0f,2.0f };

		//添字1の要素表示（1.0）
		printf("%f", c[1]);

		// 要素に-1.5代入
		c[1] = -1.5f;

		// 添え字1の要素を表示
		printf("%f", c[1]);
	}
	{
		// int型の可変長配列 d
		vector<int> d;

		// 要素数を10っこに変更
		d.resize(10);

		// 要素数を取得
		int size = d.size();

		// 全部の要素を表示
		for (int i = 0; i < size; i++) {
			printf("%f", d[i]);
		}
	}
	{
		// int型の可変長配列 e （要素数：3）
		vector<int> e = {1,2,3};

		// int型の可変長配列用のイテレータ
		vector<int>::iterator it;

		// eの先頭要素を指す
		it = e.begin();

		cout << *it << endl;

		it++;

		// it がさしている要素を表示
		cout << *it << endl;
	}

	system("pause");

	return 0;
}
