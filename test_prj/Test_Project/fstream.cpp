#include <iostream>
#include <fstream>
#include <string>

// ofstream : ����(���) - put pointer -> seekp(), tellp()
// ifstream : �б�(�Է�) - get pointer
// fstream : �б� ���� ��� - put / get pointer

// void open(const char* filename, openmode mode);
// openmode
// ios::in - �б����� ���� ����
// ios::out - �������� ���� ����
// ios::ate - ���� ���� ��ġ
// ios::app - ��� ����� ������ ���� �߰�
// ios::trunc - ���� ������ �����ϸ� ����
// ios::binary - ����(Binary) ���

// get() / put() : �ѱ��ھ� �а� ����
// seekg(streamoff offset, seek_dir origin) / seekp() : ���� �Է� �Ǵ� ��� �����͸������� origin ���κ��� offset ����Ʈ �� ��ŭ �̵��Ѵ�.

// seek_dir origin
// ios::beg - ������ ������ġ (begin)
// ios::cur - ���� ��ġ
// ios::end - ������ �� (end)

// streampos tellg() / tellp() : ���� ��ġ�� ��ȯ. seekg() / seekp() �� �����Ͽ� ����� ��� ���� �ؽ�Ʈ ��ü ���� ���� �� �� �ִ�.
// ex) seekg(0, std::ios::beg); -> get pointer �� �� ������ �̵�.
//     tellg();					-> ���� get pointer �� ��ġ�� ��ȯ

// ifstream::ignore(int num, int delim = EOF)
// ���� �Է�(�б�)�� ���� ��,
// ���� ���Ͽ��� num ���̸�ŭ �����ϰų�, delim �� ���������� ���ڸ� �а� �����ϰ� get pointer �� �̵���.

// ����
// txt ������ �о� �ٸ� ������ ���θ���� ���ڿ� �����ϴ� ���α׷�

int main()
{
	//////////////// �б�(�Է�) /////////////////

	std::ifstream ifile("INPUT.txt");	// �б��
	std::ofstream ofile;				// �����

	std::string line;		// ���κ��� �Է¹ޱ� ���� ����
	std::string result;		// ��� ���ڿ�
	int outline_size = 10;

	// ifile.is_open() : ������ ���ȴ��� �˻����ִ� �Լ�
	if (!ifile.is_open())
	{
		std::cout << "file not founded" << std::endl;

		return 0;
	}

	// ignore() �׽�Ʈ
	//ifile.ignore(50, 'a');

	// ifile.eof() : ���� ������ ������ �˻����ִ� �Լ�
	while (!ifile.eof())
	{		
		std::getline(ifile, line);
		result += line + " ";
	}

	line.clear();

	// ���� �ݱ�
	ifile.close();

	//////////////// ����(���) /////////////////

	// ����� ���� ����
	// ���ϸ��� ������ �����Ѵ�.
	// ios::_Nocreate �� ����ϸ� ������ �������� ����.
	ofile.open("NEW.txt");

	if (!ofile.is_open())
	{
		std::cout << "file not founded" << std::endl;

		return 0;
	}

	for (int start = 0; start < result.size(); )
	{
		// ���� ������ ������ ��� �Ѿ
		if (isspace(result[start]))
			++start;

		// ������ ���ڱ��̸�ŭ �߶� ����Ѵ�.
		line = result.substr(start, outline_size);

		start += outline_size;

		ofile << line + "\n";
	}

	ofile.close();

	return 0;
}