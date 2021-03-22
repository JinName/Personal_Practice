/*
소수 찾기
문제 설명
한자리 숫자가 적힌 종이 조각이 흩어져있습니다.흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.

각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

제한사항
numbers는 길이 1 이상 7 이하인 문자열입니다.
numbers는 0~9까지 숫자만으로 이루어져 있습니다.
"013"은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.
입출력 예
numbers	return
"17"	3
"011"	2
입출력 예 설명
예제 #1
[1, 7]으로는 소수[7, 17, 71]를 만들 수 있습니다.

예제 #2
[0, 1, 1]으로는 소수[11, 101]를 만들 수 있습니다.

11과 011은 같은 숫자로 취급합니다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool chk(int n)
{
    if (n < 2) return false;

    // i * i <= n 
    // 입력받은 숫자가 어떠한 숫자로 나누어 떨어질때,
    // 기준 숫자보다 큰숫자로 범위를 넘어갈 필요가 없기때문에 i * i <= n 을 사용한다.
    // ex) i = 4 일때, i(4) * 5 를 계산할 필요가 없다.
    // 이유는 i = 5 일때, i(5) * 4 와 같다.
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

void permutationN(string numbers, vector<int>& ans)
{
    // 임시 컨테이너에 숫자를 하나씩 저장
    vector<int> v;
    for (int i = 0; i < numbers.size(); ++i)
        v.push_back(numbers[i] - '0');

    // 임시 컨테이너 정렬
    sort(v.begin(), v.end());

    // next_permutation(begin, end) 를 통해 한번씩 다음 수열을 구함
    do {
        // 정렬된 숫자를 앞에서부터 하나씩 조합해서 ans 배열에 삽입
        for (int i = 0; i <= v.size(); i++) {
            int tmp = 0;
            for (int j = 0; j < i; j++) {
                tmp = (tmp * 10) + v[j];
                ans.push_back(tmp);
            }
        }
    } while (next_permutation(v.begin(), v.end()));

    // 삽입이 끝난 ans 배열 정렬
    sort(ans.begin(), ans.end());

    // 중복된 숫자 삭제
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
}

//int solution(string numbers) {
//    int answer = 0;
//    vector<int> answers;
//
//    // 수열마다 숫자조합을 정리해 answers 컨테이너에 삽입하는 함수
//    permutationN(numbers, answers);
//
//    // answers 컨테이너 내에 소수 갯수 확인
//    for (vector<int>::iterator iter = answers.begin(); iter < answers.end(); ++iter)
//        if (chk(*iter)) answer++;
//
//    return answer;
//}