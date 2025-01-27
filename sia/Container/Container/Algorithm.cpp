#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
void PrintVector(vector<int> vec)
{
	vector<int>::iterator iter1 = vec.begin();
	for (iter1; iter1 != vec.end(); iter1++)
		cout << *iter1 << " ";
	cout << endl;
}

bool Find_if(int element)
{
	if (element > 25)
		return true;
	return false;
}

int Transform_Multiply(int i) { return i * 3; }

int main()
{
	vector <int> v = { 31, 23, 3, 2, 1, 3, 12, 15, 19 };
	// 1. v���� 23�� �ִ� ������ �ڸ�(iter)�� ã��
	vector<int>::iterator iter;
	for (iter = v.begin() ; iter != v.end(); iter++)
	{
		if (*iter == 23)
			break;
	}
	cout << *iter << endl;

	iter = std::find(v.begin(), v.end(), 23);
	if (iter != v.end())
		cout << *iter << endl;

	// 2. v���� 25���� ū ���� �ִٸ� �� �ڸ� ã��
	iter = v.begin();
	for (iter; iter != v.end(); iter++)
	{
		if (*iter > 25)
			break;
	}
	cout << *iter << endl;

	iter = std::find_if(v.begin(), v.end(), &Find_if);


	struct Find_If_Functor
	{
		bool operator()(int element)
		{
			if (element > compareNum)
				return true;
			return false;
		}

		int compareNum;
	};
	Find_If_Functor functor1;
	functor1.compareNum = 25;
	iter = std::find_if(v.begin(), v.end(), functor1);

	functor1.compareNum = 27;
	iter = std::find_if(v.begin(), v.end(), functor1);

	cout << *iter << endl;
 
	// 3. v���� 3�� ������ �� ������
	int myCount1 = std::count(v.begin(), v.end(), 3);
	cout << myCount1 << endl;

	
	// 4. v���� 10���� ū ���� �� ������
	struct Count_If_Functor
	{
		bool operator()(int element)
		{
			if (element > compareNum)
				return true;
			return false;
		}

		int compareNum;
	};
	Count_If_Functor functor2;
	functor2.compareNum = 10;
	int myCount2 = std::count_if(v.begin(), v.end(), functor2);
	cout << myCount2 << endl;
	
	// 5. v���� ��� ���� 50���� ������
	struct All_Of_Functor
	{
		bool operator()(int element)
		{
			if (element < compareNum)
				return true;
			return false;
		}

		int compareNum;
	};
	All_Of_Functor functor3;
	functor3.compareNum = 50;
	bool myCount3 = std::all_of(v.begin(), v.end(), functor3);
	cout << myCount3 << endl;

	// 6. v���� �ϳ��� 20���� ũ�� 30���� ���� ���� �ִ���

	struct Any_Of_Functor
	{
		bool operator()(int element)
		{
			if (compareNum1 < element && element < compareNum2)
				return true;
			return false;
		}

		int compareNum1;
		int compareNum2;
	};
	Any_Of_Functor functor4;
	functor4.compareNum1 = 20;
	functor4.compareNum2 = 30;
	bool myCount4 = std::any_of(v.begin(), v.end(), functor4);
	cout << myCount4 << endl;
	
	// 7. v�� �迭�� �Ųٷ� ������ּ���
	std::reverse(v.begin(), v.end());
	PrintVector(v);

	// 8. �� v�� ���ҿ� 3�� �����ּ���
	std::transform(v.begin(), v.end(), v.begin(), Transform_Multiply);
	PrintVector(v);

	// 9. v�� �������ּ���
	std::sort(v.begin(), v.end());
	PrintVector(v);

	// 10. v���� �ߺ��� ���Ұ� �ִٸ� �������ּ���
	std::unique(v.begin(), v.end());
	PrintVector(v);
	
	// 11. v���� 45�� ���Ұ� �ִٸ� ����
	std::remove_copy(v.begin(), v.end(), v.begin(), 45);

	// 12. v���� 20���� ���� ���Ҹ� ����
	struct All_Of_Functor
	{
		bool operator()(int element)
		{
			if (element < compareNum)
				return true;
			return false;
		}

		int compareNum;
	};
	All_Of_Functor functor3;
	functor3.compareNum = 50;
	bool myCount3 = std::all_of(v.begin(), v.end(), functor3);
	cout << myCount3 << endl;
	return 0;
}