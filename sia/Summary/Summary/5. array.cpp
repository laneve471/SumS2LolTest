#include <iostream>

using namespace std;

//1. ��� ���� ��� 3����
// ����� ���ÿ� �ʱ�ȭ(Ref)
// #define ��ũ��
// const
// enum

// ������
// (�ڷ���)* (�����̸�) : ������ ����
// (����) * (����) : ����������
// *(����) : ����������
// (�ڷ���)** (�����̸�) : ����������

// (����) & (����) : ��Ʈ And������ -> �ٸ��� 0 ������ 1
// (����) && (����) : And������
// (�ڷ���)& (�����̸�) = (�ʱ�ȭ) : Reference ����
// &(����) : �ּҿ�����

// ������ ������
// (ptr + 1) => �ڷ����� ���� ũ�� ����

#define PI 3.141592f

// ������ ���
// ������
enum PlayerState
{
	IDLE = 5,
	Run = 1,
	FALLING = 2,
	SLEEPING = (1 << 5),
};

void PrintArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

void PrintArr(int arr[][3], int size)
{
	for (int y = 0; y < size; y++)
	{
		for (int x = 0; )
	}
}

int main()
{
	//float temp = PI; // �ٲ� �� ����

	// const (�ڷ���) : ������ => ���� �Ұ���
	const int temp = 1;
	PlayerState curState = PlayerState::IDLE;

	int temp2 = 14 & 3;

	// const (�ڷ���)* const : �б� ����
	// const �ڷ���& : �б� ����
	const int& ref = temp;
	const int* ptr = &temp;

	int aInt = 1;
	int* ptr2 = &aInt;
	cout << &aInt << endl;
	cout << (ptr2) << endl;
	cout << (ptr2 + 1) << endl;

	int arr[10]; // �����迭
	// [index] : �������ٿ�����
	// [] [] [] [] []
	// 10 14 18 1C 20
	// ���������ϴµ� �ɸ��� �ð����⵵ (���)

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	//ptr2 = &arr[0];
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << *(ptr2 + i) << ptr2[i] << arr[i] << endl;
	//}

	PrintArr(ptr2, 10);

	int arr2[2][3] = { (1, 2, 3),
					   (4, 5, 6) };

	PrintArr(&arr2[0][0], ) ��

		return 0;
}