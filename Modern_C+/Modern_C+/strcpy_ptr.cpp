#include <iostream>

char* strcpy_ptr(char* _dest, const char* _origin)
{
	while (*_origin)
	{
		*_dest++ = *_origin++;
	}

	return _dest;
}


//int main()
//{
//	char name[10] = "";
//	char name_ori[10] = "park";
//
//	strcpy_ptr(name, name_ori);
//
//	std::cout << name << std::endl;
//
//	return 0;
//}