/*
���� ����
� ���ڿ��� k���� ���� �������� �� ���� �� �ִ� ���� ū ���ڸ� ���Ϸ� �մϴ�.

���� ���, ���� 1924���� �� �� ���� �����ϸ� [19, 12, 14, 92, 94, 24] �� ���� �� �ֽ��ϴ�. �� �� ���� ū ���ڴ� 94 �Դϴ�.

���ڿ� �������� ���� number�� ������ ���� ���� k�� solution �Լ��� �Ű������� �־����ϴ�. number���� k ���� ���� �������� �� ���� �� �ִ� �� �� ���� ū ���ڸ� ���ڿ� ���·� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���� ����
number�� 1�ڸ� �̻�, 1,000,000�ڸ� ������ �����Դϴ�.
k�� 1 �̻� number�� �ڸ��� �̸��� �ڿ����Դϴ�.
����� ��
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

    // ������ Ƚ��
    int cnt = k;

    // ����
    stack<char> str_stack;

    // 1. ���ÿ� �ϳ��� �����鼭 ���Ѵ�.
    // 2. stack top �� ���� ���� �� ���ڰ� �� ũ�� stack ���� pop �ϰ� ���� ���ڸ� push �Ѵ�.
    // 2-1. ���� �� ���ں��� ���� stack ���� ���ڴ� ��� pop �ؾ��Ѵ�.
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

    // cnt ���� ����
    if (cnt > 0)
    {
        for (int i = 0; i < cnt; ++i)
        {
            str_stack.pop();
        }
    }

    // ���� ����
    while (!str_stack.empty())
    {
        answer += str_stack.top();
        str_stack.pop();
    }    

    // �����̹Ƿ� ���ڿ� ��������Ѵ�.
    reverse(answer.begin(), answer.end());

    return answer;
}

//int main()
//{
//    cout << solution("121000", 2) << endl;
//
//    return 0;
//}