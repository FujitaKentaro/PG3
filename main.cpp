#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <functional>
#include <vector>

using namespace std;

int main() {

	vector<int> b = { 10,20,30 };

	b.push_back(40); // �ǉ�
	b.pop_back();	// �폜
	{
		// �z��ƑS��������
		// float�^�̉ϒ��z�� �� �i�v�f���F3�j
		vector<float> c = { 0.0f,1.0f,2.0f };

		//�Y��1�̗v�f�\���i1.0�j
		printf("%f", c[1]);

		// �v�f��-1.5���
		c[1] = -1.5f;

		// �Y����1�̗v�f��\��
		printf("%f", c[1]);
	}
	{
		// int�^�̉ϒ��z�� d
		vector<int> d;

		// �v�f����10�����ɕύX
		d.resize(10);

		// �v�f�����擾
		int size = d.size();

		// �S���̗v�f��\��
		for (int i = 0; i < size; i++) {
			printf("%f", d[i]);
		}
	}
	{
		// int�^�̉ϒ��z�� e �i�v�f���F3�j
		vector<int> e = {1,2,3};

		// int�^�̉ϒ��z��p�̃C�e���[�^
		vector<int>::iterator it;

		// e�̐擪�v�f���w��
		it = e.begin();

		cout << *it << endl;

		it++;

		// it �������Ă���v�f��\��
		cout << *it << endl;
	}

	system("pause");

	return 0;
}
