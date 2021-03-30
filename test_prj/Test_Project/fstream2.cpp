// text ����(TEST.txt)�� �а�
// ��ü ����, ������ ����, �ܾ��� ����, ������ ����, �ܶ��� ����
// �ϳ��� �������� ���ļ� ���

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
	std::ifstream ifile("TEST.txt");

	// ��ü �ؽ�Ʈ�� �ѹ������� ����
	std::string total_text;

	// ����, �ܾ�, ����, ������ ����
	int char_cnt = 0;
	int word_cnt = 0;
	int sentence_cnt = 0;
	int paragraph_cnt = 0;

	bool in_word = false;
	bool In_paragraph = false;

	// ����ó��
	if (!ifile.is_open())
	{
		std::cout << "file not founded" << std::endl;
		return 0;
	}

	// �ؽ�Ʈ ������ �� ����
	ifile.seekg(0, std::ios::end);

	int size = ifile.tellg();
	
	ifile.seekg(0, std::ios::beg);

	// ���� ���� �б�
	while (!ifile.eof())
	{
		// get �� ����ϸ� �ؽ�Ʈ�� �о���� ifile �� ���� ������ �ϳ��� ��������.
		// ���� �� ���Ŀ� ���� �Ϸ����ϸ� ifile ���� ���۴� ��� ������ �����̱⶧���� �۵������ʴ´�.
		char c = ifile.get();
		std::cout << c;

		// ���ĺ��̸�,
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		{
			++char_cnt;

			in_word = true;
			In_paragraph = true;

			total_text += c;
		}
		// ���� , . ���� ������,
		else if (c == ' ' || c == ',' || c == '.')
		{
			if (in_word)
			{
				++word_cnt;
				in_word = false;

				// . �� ������ ���� �ϳ��� �������̴�.
				if (c == '.')
					++sentence_cnt;
			}		

			total_text += c;
		}
		// ������ ������,
		else if (c == '\n')
		{
			if (In_paragraph)
			{
				++paragraph_cnt;

				In_paragraph = false;
			}		
		}

		if (ifile.eof() && c != '\n')
			++paragraph_cnt;
	}

	std::cout << std::endl;

	std::cout << "Total Size : " << size << std::endl;
	std::cout << "Char Count : " << char_cnt << std::endl;
	std::cout << "Word Count : " << word_cnt << std::endl;
	std::cout << "Sentence Count : " << sentence_cnt << std::endl;
	std::cout << "Paragraph Count : " << paragraph_cnt << std::endl;	

	ifile.close();

	// ���� ����

	std::ofstream ofile("RESULT.txt");

	std::cout << total_text << std::endl;

	ofile << total_text;

	ofile.close();

	return 0;
}