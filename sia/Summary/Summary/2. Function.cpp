#include <iostream>

using namespace std;

// �����Լ�
// y + f(x)
// ��ȯ�ڷ��� �Լ��̸�(�Ű�����) => �Լ� �ñ״�ó
// �Լ� ���� ���
// void : ������

// ������ ������
// *ptr : ����������, ��Ż������ -> �����Ͱ� ����ִ� �ּҰ����� ��Ż Ÿ�� ��
// &(����) : �ּҿ����� -> ������ ����ִ� �ּҰ�

// ����������
// - �Լ��� ȣ��� �� �Ű�����, ��ȯ�ּҰ�, ��������
// - �Ű�����, ��ȯ�ּҰ�, �������� (1mb �Ҵ�, ���� �����÷ο�)
// - ���Լ���(LIFO)
// - ������ �ð��� ũ�Ⱑ ����
// - ���� �ּ� -> ���� �ּ�
// ip (Instruction Pointer) : ���� ���� ��ɾ��� ��ġ
// sp(Stack Pointer) : ���� ���� top ��ġ(������ cursor)
// bp(Base Pointer) : ���� ����ּ� ����

// ������, ���� ����
// - �������� �ּҰ� ����Ű�� �� �ּҰ��� �ٸ�
// - �����ʹ� ������ �޸� �Ҵ�
// - ������ ����
// - ������ null ����ų �� ����, ����
// - ������ �Ҵ�� ��ü �ٲ� �� ����

void HelloWorld()
{
	cout << "Hello World!" << endl;
}


// Call by Value
void AddOne(int num)
{
	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������(aInt(3))], Add[��ȯ�ּҰ�(&aInt), �Ű����� (num : 3) �������� ()]
	num++;
	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������(aInt(3))], Add[��ȯ�ּҰ�(&aInt), �Ű����� (num : 4) �������� ()]

}

// Call by Address
void AddOne(int* ptr)
{
	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������((0x12)aInt(3))], Add[��ȯ�ּҰ�(&aInt), �Ű����� (ptr : 0x12) �������� ()]
	(*ptr)++;
	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������((0x12)aInt(4))], Add[��ȯ�ּҰ�(&aInt), �Ű����� (ptr : 0x12) �������� ()]
}


// ���� �̸��� �ٸ� ���� -> �Լ� �����ε�
// �ٸ� ���� : �Ű������� �ڷ����̳� ������ �ٸ� ��
int Add(int a, int b) {
	int c = a + b;

	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������(aInt(cccccccc))], Add[��ȯ�ּҰ�(&aInt), �Ű����� (a 1, b 2) �������� c(3)]
	cout << c << endl;

	return c;
}

int Add(int a, int b, int c)
{
	int d = Add(a, b) + c;

	return d;
}

// �Լ� �Ű������� �⺻���� -> �Ű�����(����, �Ķ����, argument). ������ �� �ں���
int Add(int a, int b, int c, int d, int e = 1)
{
	int f = Add(a, b, c) + d + e;

	return f;
}

int Add(int a, int b, int c, int d)
{
	int e = a + b + c + d;

	return e;
}


// ���ȣ�� : ���� �����÷ο� -> ���ÿ� �� �̻� �Ҵ� �Ұ�
int Factorial(int num)
{
	if (num == 1)
		return 1;

	return num * Factorial(num - 1);
}


// �޸������̼� : ������ ����� ���� �����صΰ� ����
int cache[200] = {}; // ��������
int Fibonacchi(int num)
{
	if (num == 0 || num == 1)
		return 1;

	int* ref = &cache[num];
	if (*ref != 0)
		return *ref;

	*ref = Fibonacchi(num - 1) + Fibonacchi(num - 2); // cache[2] = 2

	return *ref;
}


int main()
{
	HelloWorld();

	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������(aInt(cccccccc))]

	int aInt = Add(1, 2); // aInt�� c�� �ٸ�

	AddOne(aInt);
	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������(aInt(3))]

	AddOne(&aInt);
	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������((0x12)aInt(4))]

	//aInt = Add(1, 2, 3, 4); // ȥ��-> �Ű����� 4��? 5��?

	aInt = Factorial(5);

	aInt = Fibonacchi(100);

	cout << aInt << endl;

	return 0;
}