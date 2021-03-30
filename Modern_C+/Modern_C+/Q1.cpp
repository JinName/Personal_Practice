// 1. 다음 구문 중 잘못된 것을 모두 고르시오.

/*

#include <iostream>


int main()
{
	const char* p = "hello";

	char* s = "yahoo";		// 프로젝트 속성 > c++ > 언어 > 준수모드 off

	int i = 1;

	int* ip = &i;

	void* vp = &i;

	// 보기 ////////////////////

	//s = p;	// char* <- const char* : 불가능

	p = s;		// const char* <- char* : 가능

	vp = ip;	// void* <- int* : 가능

	//ip = vp;	// int* -> void* : 불가능

	// 보기 ////////////////////

	return 0;
}

*/