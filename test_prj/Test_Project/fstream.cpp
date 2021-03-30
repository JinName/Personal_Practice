#include <iostream>
#include <fstream>
#include <string>

// ofstream : 쓰기(출력) - put pointer -> seekp(), tellp()
// ifstream : 읽기(입력) - get pointer
// fstream : 읽기 쓰기 모두 - put / get pointer

// void open(const char* filename, openmode mode);
// openmode
// ios::in - 읽기위한 파일 열기
// ios::out - 쓰기위한 파일 열기
// ios::ate - 파일 끝에 위치
// ios::app - 모든 출력은 파일의 끝에 추가
// ios::trunc - 만약 파일이 존재하면 지움
// ios::binary - 이진(Binary) 모드

// get() / put() : 한글자씩 읽고 쓰기
// seekg(streamoff offset, seek_dir origin) / seekp() : 현재 입력 또는 출력 포인터를지정된 origin 으로부터 offset 바이트 수 만큼 이동한다.

// seek_dir origin
// ios::beg - 파일의 시작위치 (begin)
// ios::cur - 현재 위치
// ios::end - 파일의 끝 (end)

// streampos tellg() / tellp() : 현재 위치값 반환. seekg() / seekp() 와 연계하여 사용할 경우 파일 텍스트 전체 길이 등을 알 수 있다.
// ex) seekg(0, std::ios::beg); -> get pointer 를 맨 끝으로 이동.
//     tellg();					-> 현재 get pointer 의 위치값 반환

// ifstream::ignore(int num, int delim = EOF)
// 파일 입력(읽기)을 받을 때,
// 읽은 파일에서 num 길이만큼 무시하거나, delim 를 만날때까지 문자를 읽고 무시하고 get pointer 를 이동함.

// 예제
// txt 파일을 읽어 다른 파일을 새로만들어 문자열 저장하는 프로그램

int main()
{
	//////////////// 읽기(입력) /////////////////

	std::ifstream ifile("INPUT.txt");	// 읽기용
	std::ofstream ofile;				// 쓰기용

	std::string line;		// 라인별로 입력받기 위한 변수
	std::string result;		// 결과 문자열
	int outline_size = 10;

	// ifile.is_open() : 파일이 열렸는지 검사해주는 함수
	if (!ifile.is_open())
	{
		std::cout << "file not founded" << std::endl;

		return 0;
	}

	// ignore() 테스트
	//ifile.ignore(50, 'a');

	// ifile.eof() : 현재 파일의 끝인지 검사해주는 함수
	while (!ifile.eof())
	{		
		std::getline(ifile, line);
		result += line + " ";
	}

	line.clear();

	// 파일 닫기
	ifile.close();

	//////////////// 쓰기(출력) /////////////////

	// 쓰기용 파일 생성
	// 파일명이 없으면 생성한다.
	// ios::_Nocreate 을 사용하면 파일을 생성하지 않음.
	ofile.open("NEW.txt");

	if (!ofile.is_open())
	{
		std::cout << "file not founded" << std::endl;

		return 0;
	}

	for (int start = 0; start < result.size(); )
	{
		// 문장 시작이 공백일 경우 넘어감
		if (isspace(result[start]))
			++start;

		// 지정된 문자길이만큼 잘라서 출력한다.
		line = result.substr(start, outline_size);

		start += outline_size;

		ofile << line + "\n";
	}

	ofile.close();

	return 0;
}