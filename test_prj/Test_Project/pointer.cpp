
#include <iostream>

int main()
{
	const char* p = "hello";

	char* s = "yahoo";		// ������Ʈ �Ӽ� > c++ > ��� > �ؼ���� off

	int i = 1;

	int* ip = &i;

	void* vp = &i;

	// ���� ////////////////////

	//s = p;	// char* <- const char* : �Ұ��� but ������ ��ȯ�� ���� �����ϰ� ���� �� �ִ�.
	s = (char*)p;

	p = s;		// const char* <- char* : ����

	vp = ip;	// void* <- int* : ����

	//ip = vp;	// int* <- void* : �Ұ��� but ������ ��ȯ�� ���� �����ϰ� ���� �� �ִ�.
	ip = (int*)vp;

	// ���� ////////////////////

	std::cout << *ip << std::endl;
	std::cout << s << std::endl;

	return 0;
}
