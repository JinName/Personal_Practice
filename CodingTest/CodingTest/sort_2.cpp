/*
���� ū ��

���� ����
0 �Ǵ� ���� ������ �־����� ��, ������ �̾� �ٿ� ���� �� �ִ� ���� ū ���� �˾Ƴ� �ּ���.

���� ���, �־��� ������ [6, 10, 2]��� [6102, 6210, 1062, 1026, 2610, 2106]�� ���� �� �ְ�, ���� ���� ū ���� 6210�Դϴ�.

0 �Ǵ� ���� ������ ��� �迭 numbers�� �Ű������� �־��� ��, ������ ���ġ�Ͽ� ���� �� �ִ� ���� ū ���� ���ڿ��� �ٲپ� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���� ����
numbers�� ���̴� 1 �̻� 100,000 �����Դϴ�.
numbers�� ���Ҵ� 0 �̻� 1,000 �����Դϴ�.
������ �ʹ� Ŭ �� ������ ���ڿ��� �ٲپ� return �մϴ�.
����� ��
numbers	return
[6, 10, 2]	"6210"
[3, 30, 34, 5, 9]	"9534330"
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(int _a, int _b)
{
    string str_a = to_string(_a);
    string str_b = to_string(_b);

    return stoi(str_a + str_b) > stoi(str_b + str_a);
}

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), compare);

    if (numbers[0] == 0)
        return "0";

    for (auto& elem : numbers)
    {
        answer += to_string(elem);
    }

    return answer;
}

//void main()
//{
//    string result = solution({ 40, 403 });
//
//    cout << result << endl;
//}