// 정규식 표현

// 1. 주어진 문자열이 주어진 규칙에 맞는지 확인할 때
// 2. 주어진 문자열에서 원하는 패턴의 문자열을 검색할 때
// 3. 주어진 문자열에서 원하는 패턴의 문자열로 치환할 때

// std::regex

// std::regex_match - 정규 표현식으로 문자열 패턴 매칭
// std::regex_search - 정규 표현식으로 문자열 검색
// std::regex_replace - 정규 표현식으로 문자열 치환

#include <iostream>
#include <string>
#include <regex>
#include <vector>

int main(int argc, char* argv[])
{
	// 특정한 문자열 규칙에 대한 정규식을 통해
	// 해당 문자열이 부합하는지 확인
	
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

	// 전화번호에 대한 정규식 표현을 통해 문자열 검사
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
	
	// smatch 객체로 괄호 내의 문자열 얻기
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

	// 특정 문자패턴에 부합하는 문자열만 찾기
	// std::regex_search
	std::string html = R"(
        <div class="social-login">
          <div class="small-comment">다음으로 로그인 </div>
          <div>
            <i class="xi-facebook-official fb-login"></i>
            <i class="xi-google-plus goog-login"></i>
          </div>
        </div>
        <div class="manual">
          <div class="small-comment">
            또는 직접 입력하세요 (댓글 수정시 비밀번호가 필요합니다)
          </div>
          <input name="name" id="name" placeholder="이름">
          <input name="password" id="password" type="password" placeholder="비밀번호">
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
	
	// 특정 문자열 패턴을 원하는 문자열로 치환하기
	// std::regex_replace
	std::string html2 = R"(
        <div class="social-login">
          <div class="small-comment">다음으로 로그인 </div>
          <div>
            <i class="xi-facebook-official fb-login"></i>
            <i class="xi-google-plus goog-login"></i>
          </div>
        </div>
        <div class="manual">
          <div class="small-comment">
            또는 직접 입력하세요 (댓글 수정시 비밀번호가 필요합니다)
          </div>
          <input name="name" id="name" placeholder="이름">
          <input name="password" id="password" type="password" placeholder="비밀번호">
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

	// 중첩 캡처
	// 괄호가 열리는 순서대로 $1, $2... 그룹이 된다.
	std::regex reg6("(sk-circle(\\d) sk-circle)");

	std::string fixed_html2 = std::regex_replace(html2, reg6, "$2-sk-circle");

	std::cout << fixed_html2 << std::endl;	

	std::cout << sizeof(short int) << std::endl;

	return 0;
}
