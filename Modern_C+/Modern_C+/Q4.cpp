// 4. 다음의 실행 결과를 예측하시오

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

// 정답

/*
* Head
* Man
* ~Man
* ~Head
*/

// C++ 중첩클래스에 대한 기초지식 필요
