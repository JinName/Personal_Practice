// 1. ���� ���� �� �߸��� ���� ��� ���ÿ�.

/*

#include <iostream>


int main()
{
	const char* p = "hello";

	char* s = "yahoo";		// ������Ʈ �Ӽ� > c++ > ��� > �ؼ���� off

	int i = 1;

	int* ip = &i;

	void* vp = &i;

	// ���� ////////////////////

	//s = p;	// char* <- const char* : �Ұ���

	p = s;		// const char* <- char* : ����

	vp = ip;	// void* <- int* : ����

	//ip = vp;	// int* -> void* : �Ұ���

	// ���� ////////////////////

	return 0;
}

*/