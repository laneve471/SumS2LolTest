#include <iostream>

using namespace std;

//ref
// (�ڷ���)& (Ref �̸�) = (�ʱ�ȭ);
// - C++ ���� : �ش� ������ ����
// - ������� : �����Ͷ� 
// - ũ�� : 32��Ʈ(4) 64��Ʈ (8)

// ptr, ref ����
// 1. �����ʹ� �߰��� ��� ���� ���� / Ref�� �߰��� ��� ���� �Ұ�
// 2. �����ʹ� nullptr�� ������ �� �ִ� / Ref�� ���� ���� ������ �� ����
// 3. �����ʹ� �ʱ�ȭ�� ���� �ʾƵ� �ȴ� / Ref�� ������ �ʱ�ȭ

// ��� ���� 3���� ����

// Call by value
// �Ű����� value�� �б�, ���� �����ϴ�
// ���� ���� �Ұ�. ���� �б�(����) ����
/*
void AddOne(int num)
{
	num++;
}
*/

// Call by address
// �Ű����� ptr�� Ÿ�� ���� �б� ���� ����
// ���� ���� ����
// ���� �����(�޸� ����)
void AddOne(int* const ptr) // 0x12
{
	// ptr = (int*) 0x12341234 -> �޸� ����

	(*ptr)++;
}

// Call by reference
// �Ű����� ref(����)�� ���� �б� ���� ����
// ������ ������ �� �ִ�
// -> ���� ����
void AddOne(int& ref)
{
	ref++;
}

int main()
{
	int aInt = 1;
	int bInt = 2;

	int* ptr = &aInt; //0xcccccccc
	ptr = NULL;

	int& ref = aInt;
	ref = bInt; // aInt�� bInt �� �Ҵ�

	cout << aInt << endl; // 2 ���
	cout << ref << endl;
	cout << bInt << endl;

	aInt = 1;
	AddOne(&aInt); // (0x12)aInt
	AddOne(aInt);

	cout << aInt << endl;

	return 0;
}