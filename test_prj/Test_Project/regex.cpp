// ���Խ� ǥ��

// 1. �־��� ���ڿ��� �־��� ��Ģ�� �´��� Ȯ���� ��
// 2. �־��� ���ڿ����� ���ϴ� ������ ���ڿ��� �˻��� ��
// 3. �־��� ���ڿ����� ���ϴ� ������ ���ڿ��� ġȯ�� ��

// std::regex

// std::regex_match - ���� ǥ�������� ���ڿ� ���� ��Ī
// std::regex_search - ���� ǥ�������� ���ڿ� �˻�
// std::regex_replace - ���� ǥ�������� ���ڿ� ġȯ

#include <iostream>
#include <string>
#include <regex>
#include <vector>

int main(int argc, char* argv[])
{
	// Ư���� ���ڿ� ��Ģ�� ���� ���Խ��� ����
	// �ش� ���ڿ��� �����ϴ��� Ȯ��
	
	std::vector<std::string> file_name = {
		"db-123-log.txt", "db-124-log.txt",
		"not-db-log.txt", "db-12-log.txt",
		"db-12-log.jpg"
	};

	std::regex reg1("db-\\d*-log\\.txt");

	for (auto& name : file_name)
	{
		std::cout << name << " : " << std::boolalpha << std::regex_match(name, reg1) << std::endl;
	}

	std::cout << std::endl;

	// ��ȭ��ȣ�� ���� ���Խ� ǥ���� ���� ���ڿ� �˻�
	std::vector<std::string> phone_numbers = {
		"010-1234-5678", "010-123-4567",
		"011-1234-5567", "010-12345-6789",
		"123-4567-8901", "010-1234-567"
	};

	std::regex reg2("[01]{3}-\\d{3,4}-\\d{4}");

	for (auto& number : phone_numbers)
	{
		std::cout << number << " : " << std::boolalpha << std::regex_match(number, reg2) << std::endl;
	}

	std::cout << std::endl;
	
	// smatch ��ü�� ��ȣ ���� ���ڿ� ���
	std::regex reg3("[01]{3}-(\\d{3,4})-\\d{4}");
	std::smatch match;

	for (auto& number : phone_numbers)
	{
		if (std::regex_match(number, match, reg3))
		{
			for (auto& m : match)
			{
				std::cout << "Match : " << m.str() << std::endl;
			}
		}
	}

	std::cout << std::endl;

	// Ư�� �������Ͽ� �����ϴ� ���ڿ��� ã��
	// std::regex_search
	std::string html = R"(
        <div class="social-login">
          <div class="small-comment">�������� �α��� </div>
          <div>
            <i class="xi-facebook-official fb-login"></i>
            <i class="xi-google-plus goog-login"></i>
          </div>
        </div>
        <div class="manual">
          <div class="small-comment">
            �Ǵ� ���� �Է��ϼ��� (��� ������ ��й�ȣ�� �ʿ��մϴ�)
          </div>
          <input name="name" id="name" placeholder="�̸�">
          <input name="password" id="password" type="password" placeholder="��й�ȣ">
        </div>
		<div id="adding-comment" class="sk-fading-circle">
          <div class="sk-circle1 sk-circle">a</div>
          <div class="sk-circle2 sk-circle">b</div>
          <div class="sk-circle3 sk-circle">asd</div>
          <div class="sk-circle4 sk-circle">asdfasf</div>
          <div class="sk-circle5 sk-circle">123</div>
          <div class="sk-circle6 sk-circle">aax</div>
          <div class="sk-circle7 sk-circle">sxz</div>
        </div>)";

	std::regex reg4(R"(<div class="sk[\w -]*">\w*</div>)");
	std::smatch match2;

	while (std::regex_search(html, match2, reg4))
	{
		std::cout << match2.str() << '\n';
		html = match2.suffix();
	}

	std::cout << std::endl;
	
	// Ư�� ���ڿ� ������ ���ϴ� ���ڿ��� ġȯ�ϱ�
	// std::regex_replace
	std::string html2 = R"(
        <div class="social-login">
          <div class="small-comment">�������� �α��� </div>
          <div>
            <i class="xi-facebook-official fb-login"></i>
            <i class="xi-google-plus goog-login"></i>
          </div>
        </div>
        <div class="manual">
          <div class="small-comment">
            �Ǵ� ���� �Է��ϼ��� (��� ������ ��й�ȣ�� �ʿ��մϴ�)
          </div>
          <input name="name" id="name" placeholder="�̸�">
          <input name="password" id="password" type="password" placeholder="��й�ȣ">
        </div>
		<div id="adding-comment" class="sk-fading-circle">
          <div class="sk-circle1 sk-circle">a</div>
          <div class="sk-circle2 sk-circle">b</div>
          <div class="sk-circle3 sk-circle">asd</div>
          <div class="sk-circle4 sk-circle">asdfasf</div>
          <div class="sk-circle5 sk-circle">123</div>
          <div class="sk-circle6 sk-circle">aax</div>
          <div class="sk-circle7 sk-circle">sxz</div>
        </div>)";

	std::regex reg5("sk-circle(\\d)");

	std::string fixed_html = std::regex_replace(html2, reg5, "$1-sk-circle");

	std::cout << fixed_html << std::endl;

	std::cout << std::endl;

	// ��ø ĸó
	// ��ȣ�� ������ ������� $1, $2... �׷��� �ȴ�.
	std::regex reg6("(sk-circle(\\d) sk-circle)");

	std::string fixed_html2 = std::regex_replace(html2, reg6, "$2-sk-circle");

	std::cout << fixed_html2 << std::endl;	

	std::cout << sizeof(short int) << std::endl;

	return 0;
}
