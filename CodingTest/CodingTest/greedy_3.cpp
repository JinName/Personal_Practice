/*
문제 설명
어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.

예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다. 이 중 가장 큰 숫자는 94 입니다.

문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다. number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요.

제한 조건
number는 1자리 이상, 1,000,000자리 이하인 숫자입니다.
k는 1 이상 number의 자릿수 미만인 자연수입니다.
입출력 예
number	        k	    return
"1924"	        2	    "94"
"1231234"	    3	    "3234"
"4177252841"	4	    "775841"
*/

#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    // 제거할 횟수
    int cnt = k;

    // 스택
    stack<char> str_stack;

    // 1. 스택에 하나씩 넣으면서 비교한다.
    // 2. stack top 과 비교해 현재 비교 숫자가 더 크면 stack 에서 pop 하고 현재 숫자를 push 한다.
    // 2-1. 현재 비교 숫자보다 작은 stack 내의 숫자는 모두 pop 해야한다.
    for (int i = 0; i < number.length(); ++i)
    {
        if (str_stack.empty())
        {
            str_stack.push(number[i]);
        }
        else
        {
            if (str_stack.top() - '0' >= number[i] - '0')
            {
                str_stack.push(number[i]);
            }
            else
            {
                while (cnt != 0 && !str_stack.empty() && str_stack.top() - '0' < number[i] - '0')
                {
                    str_stack.pop();
                    --cnt;
                }

                str_stack.push(number[i]);
            }
        }
    }

    // cnt 여분 제거
    if (cnt > 0)
    {
        for (int i = 0; i < cnt; ++i)
        {
            str_stack.pop();
        }
    }

    // 문자 정렬
    while (!str_stack.empty())
    {
        answer += str_stack.top();
        str_stack.pop();
    }    

    // 스택이므로 문자열 뒤집어야한다.
    reverse(answer.begin(), answer.end());

    return answer;
}

//int main()
//{
//    cout << solution("121000", 2) << endl;
//
//    return 0;
//}