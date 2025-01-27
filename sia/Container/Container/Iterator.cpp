#include <iostream>
#include <vector>
#include <list>
#include "List.h"
#include "Vector.h"

using namespace std;

// iterator : �ݺ���(��ȸ��)

int main()
{
	vector<int> v = { 1,2,3,4,5,6 };

	// vector�� �������ٿ����ڷ� ��ȸ�� ����. list�� �Ұ�
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	// vector�� iter�� ��ȸ�ϴ� ���
	vector<int>::iterator iter;
	iter = v.begin();
	for (iter; iter != v.end(); iter++)
	{
		cout << *iter << endl;
	}

	cout << "------------" << endl;
	

	return 0;
}