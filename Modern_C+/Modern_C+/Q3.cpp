// 3. ������ �������� �����Ͻÿ�

/*

#include <iostream>

int Foo();
void Foo(int j);

int j = Foo();

int main()
{
	int j = 2;

	Foo(j);

	std::cout << "j:" << j << "::j" << ::j << std::endl;

	return 0;
}

int Foo()
{
	return 2;
}

void Foo(int j)
{
	::j += j;
}

*/

// ���� : j:2::j4

// :: - ���� Ȯ�� ������
// ���� �ٸ� �������� ���Ǵ� �ĺ��ڸ� �����ϴµ��� ���ȴ�.
// ::j = the 'j' in the global namespace