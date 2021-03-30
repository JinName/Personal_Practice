// text 파일(TEST.txt)을 읽고
// 전체 길이, 문자의 갯수, 단어의 갯수, 문장의 갯수, 단락의 갯수
// 하나의 문단으로 합쳐서 출력

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
	std::ifstream ifile("TEST.txt");

	// 전체 텍스트를 한문단으로 저장
	std::string total_text;

	// 문자, 단어, 문장, 문단의 갯수
	int char_cnt = 0;
	int word_cnt = 0;
	int sentence_cnt = 0;
	int paragraph_cnt = 0;

	bool in_word = false;
	bool In_paragraph = false;

	// 예외처리
	if (!ifile.is_open())
	{
		std::cout << "file not founded" << std::endl;
		return 0;
	}

	// 텍스트 파일의 총 길이
	ifile.seekg(0, std::ios::end);

	int size = ifile.tellg();
	
	ifile.seekg(0, std::ios::beg);

	// 파일 버퍼 읽기
	while (!ifile.eof())
	{
		// get 을 사용하면 텍스트를 읽어들인 ifile 의 버퍼 내용이 하나씩 지워진다.
		// 따라서 이 이후에 뭔가 하려고하면 ifile 내의 버퍼는 모두 지워진 상태이기때문에 작동하지않는다.
		char c = ifile.get();
		std::cout << c;

		// 알파벳이면,
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		{
			++char_cnt;

			in_word = true;
			In_paragraph = true;

			total_text += c;
		}
		// 공백 , . 등이 나오면,
		else if (c == ' ' || c == ',' || c == '.')
		{
			if (in_word)
			{
				++word_cnt;
				in_word = false;

				// . 이 나오면 문장 하나가 끝난것이다.
				if (c == '.')
					++sentence_cnt;
			}		

			total_text += c;
		}
		// 개행이 나오면,
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

	// 파일 쓰기

	std::ofstream ofile("RESULT.txt");

	std::cout << total_text << std::endl;

	ofile << total_text;

	ofile.close();

	return 0;
}