#include <fstream>
#include <iostream>

//int main()
//{
//	//std::ofstream ofile("test.txt");
//	std::string str;
//
//	//if (ofile.is_open())
//	//{
//	//	std::cin >> str;
//	//	ofile << str;
//	//	str.clear();
//	//}	
//
//	//ofile.close();
//
//	std::ifstream ifile("test.txt");	
//
//	if (ifile.is_open())
//	{
//		// 파일을 한줄씩 읽음.
//		ifile >> str;
//		ifile >> str;
//
//		str.clear();
//	}
//
//	if (ifile.is_open())
//	{
//		// 파일의 끝지점으로 포지션 이동
//		ifile.seekg(0, std::ios::end);
//
//		// tellg -> 현재 위치값 반환 : 즉, 파일내 커서 포지션을 end로 옮긴후 tellg() 를 호출하면 파일 내 문자열 길이를 알 수 있음.
//		int size = ifile.tellg();
//
//		// str 사이즈 지정
//		str.resize(size);
//
//		// 파일의 시작지점으로 포지션 이동
//		ifile.seekg(0, std::ios::beg);
//
//		// 파일 내용 읽기
//		ifile.read(&str[0], size);
//
//		std::cout << str << std::endl;
//	}
//
//	return 0;
//}