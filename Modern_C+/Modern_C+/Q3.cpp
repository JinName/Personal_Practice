// 3. 다음의 실행결과를 예측하시오

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

// 정답 : j:2::j4

// :: - 범위 확인 연산자
// 서로 다른 범위에서 사용되는 식별자를 구분하는데에 사용된다.
// ::j = the 'j' in the global namespace