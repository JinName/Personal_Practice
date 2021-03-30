
#include <iostream>

int main()
{
	const char* p = "hello";

	char* s = "yahoo";		// 프로젝트 속성 > c++ > 언어 > 준수모드 off

	int i = 1;

	int* ip = &i;

	void* vp = &i;

	// 보기 ////////////////////

	//s = p;	// char* <- const char* : 불가능 but 강제형 변환을 통해 가능하게 만들 수 있다.
	s = (char*)p;

	p = s;		// const char* <- char* : 가능

	vp = ip;	// void* <- int* : 가능

	//ip = vp;	// int* <- void* : 불가능 but 강제형 변환을 통해 가능하게 만들 수 있다.
	ip = (int*)vp;

	// 보기 ////////////////////

	std::cout << *ip << std::endl;
	std::cout << s << std::endl;

	return 0;
}
