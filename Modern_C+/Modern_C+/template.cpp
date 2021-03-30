#include <iostream>

// �Լ� ���ø�
template <typename T>
T sum(T _a, T _b)
{
	return _a + _b;
}

// ���ø� Ư��ȭ
template <>
char* sum<char*>(char* _a, char* _b)
{
	std::cout << _a << std::endl;
	std::cout << _b << std::endl;

	return NULL;
}

// �Ű������� �ٸ� Ÿ���� ������
template <typename T1, typename T2>
auto div(T1 _a, T2 _b) -> decltype(_a / _b)
{
	return _a / _b;
}

// typename �� class �� ���� : ���� ������
// ���ø��� ��ø ������ ������ ��� ��� typename �� class �� �����Ͽ� �����.
// class Ű����� c++ ǥ��ȭ ������ ���̴� Ű�����̴�.
// typename �� ǥ�� ���� ����ϰ� �� Ű����
// ȣȯ���� ���� �����Ϸ����� �Ѵ� �����ϴ� ���̴�.
//
//int main()
//{
//	auto result = sum(std::string("afd"), std::string("arha"));
//
//	std::cout << result << std::endl;
//
//	return 0;
//}