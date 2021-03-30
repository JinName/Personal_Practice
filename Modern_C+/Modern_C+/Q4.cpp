// 4. ������ ���� ����� �����Ͻÿ�

#include <iostream>

class Man
{
	class Head
	{
	public:
		Head() { std::cout << "Head" << std::endl; }

		virtual ~Head() { std::cout << "~Head" << std::endl; }
	};

	Head head;

public:
	Man() { std::cout << "Man" << std::endl; }

	virtual ~Man() { std::cout << "~Man" << std::endl; }
};

int main()
{
	Man man;

	return 0;
}

// ����

/*
* Head
* Man
* ~Man
* ~Head
*/

// C++ ��øŬ������ ���� �������� �ʿ�
