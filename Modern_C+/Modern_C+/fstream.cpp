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
//		// ������ ���پ� ����.
//		ifile >> str;
//		ifile >> str;
//
//		str.clear();
//	}
//
//	if (ifile.is_open())
//	{
//		// ������ ���������� ������ �̵�
//		ifile.seekg(0, std::ios::end);
//
//		// tellg -> ���� ��ġ�� ��ȯ : ��, ���ϳ� Ŀ�� �������� end�� �ű��� tellg() �� ȣ���ϸ� ���� �� ���ڿ� ���̸� �� �� ����.
//		int size = ifile.tellg();
//
//		// str ������ ����
//		str.resize(size);
//
//		// ������ ������������ ������ �̵�
//		ifile.seekg(0, std::ios::beg);
//
//		// ���� ���� �б�
//		ifile.read(&str[0], size);
//
//		std::cout << str << std::endl;
//	}
//
//	return 0;
//}