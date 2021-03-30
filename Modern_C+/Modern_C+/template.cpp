#include <iostream>

// 함수 템플릿
template <typename T>
T sum(T _a, T _b)
{
	return _a + _b;
}

// 템플릿 특수화
template <>
char* sum<char*>(char* _a, char* _b)
{
	std::cout << _a << std::endl;
	std::cout << _b << std::endl;

	return NULL;
}

// 매개변수로 다른 타입을 받을때
template <typename T1, typename T2>
auto div(T1 _a, T2 _b) -> decltype(_a / _b)
{
	return _a / _b;
}

// typename 과 class 의 차이 : 거의 없지만
// 템플릿이 중첩 의존의 형식을 띄는 경우 typename 과 class 를 구분하여 써야함.
// class 키워드는 c++ 표준화 이전에 쓰이던 키워드이다.
// typename 이 표준 이후 사용하게 된 키워드
// 호환성을 위해 컴파일러에서 둘다 지원하는 것이다.
//
//int main()
//{
//	auto result = sum(std::string("afd"), std::string("arha"));
//
//	std::cout << result << std::endl;
//
//	return 0;
//}