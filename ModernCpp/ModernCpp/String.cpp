#include <iostream>

using namespace std;

// ���ڿ� Ư¡
// - �� �� ��Ʈ�� 0���� ������ ���ڿ��� �����ٰ� �Ǵ�
// - Escape Sequence
// -- '\0' : 0
// -- '\t' : tap
// -- '\'' : '
// -- '\n' : ���� ��

// ���ڿ��� ����
unsigned __int64 Length(const char* str)
{
	unsigned __int64 count = 0;
	for (str; *str != '\0'; str++)
	{
		count++;
	}
	return count;
}

unsigned __int64 Length(const char* str)
{
	unsigned __int64 count = 0;
	for (int i = 0; ; i++)
	{
		if (str[i] == '\0')
			break;
		count++;
	}
	return count;
}

// ���ڿ� ��
bool Compare(const char* str1, const char* str2)
{
	bool compare = true;

	while (*str1 != '\0' && *str2 != '\0' && compare)
	{
		if (*str1 != *str2)
		{
			compare = false;
		}
		str1++;
		str2++;
	}
	return compare;
}
/*
bool Compare(const)
{
	int length1 = Length(str1);
	if (length1 != Length(str2))
		return false;
}
*/

int main()
{
	const char* str1 = "Hello"; // \0 ��������
	const char* str2 = "Helo";
	//char str2[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };

	cout << str1 << endl;
	cout << str2 << endl;

	cout << Length(str1) << endl;
	cout << Compare(str1, str2) << endl;
}