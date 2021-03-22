/*
�Ҽ� ã��
���� ����
���ڸ� ���ڰ� ���� ���� ������ ������ֽ��ϴ�.����� ���� ������ �ٿ� �Ҽ��� �� �� ���� �� �ִ��� �˾Ƴ��� �մϴ�.

�� ���� ������ ���� ���ڰ� ���� ���ڿ� numbers�� �־����� ��, ���� �������� ���� �� �ִ� �Ҽ��� �� ������ return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
numbers�� ���� 1 �̻� 7 ������ ���ڿ��Դϴ�.
numbers�� 0~9���� ���ڸ����� �̷���� �ֽ��ϴ�.
"013"�� 0, 1, 3 ���ڰ� ���� ���� ������ ������ִٴ� �ǹ��Դϴ�.
����� ��
numbers	return
"17"	3
"011"	2
����� �� ����
���� #1
[1, 7]���δ� �Ҽ�[7, 17, 71]�� ���� �� �ֽ��ϴ�.

���� #2
[0, 1, 1]���δ� �Ҽ�[11, 101]�� ���� �� �ֽ��ϴ�.

11�� 011�� ���� ���ڷ� ����մϴ�.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool chk(int n)
{
    if (n < 2) return false;

    // i * i <= n 
    // �Է¹��� ���ڰ� ��� ���ڷ� ������ ��������,
    // ���� ���ں��� ū���ڷ� ������ �Ѿ �ʿ䰡 ���⶧���� i * i <= n �� ����Ѵ�.
    // ex) i = 4 �϶�, i(4) * 5 �� ����� �ʿ䰡 ����.
    // ������ i = 5 �϶�, i(5) * 4 �� ����.
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

void permutationN(string numbers, vector<int>& ans)
{
    // �ӽ� �����̳ʿ� ���ڸ� �ϳ��� ����
    vector<int> v;
    for (int i = 0; i < numbers.size(); ++i)
        v.push_back(numbers[i] - '0');

    // �ӽ� �����̳� ����
    sort(v.begin(), v.end());

    // next_permutation(begin, end) �� ���� �ѹ��� ���� ������ ����
    do {
        // ���ĵ� ���ڸ� �տ������� �ϳ��� �����ؼ� ans �迭�� ����
        for (int i = 0; i <= v.size(); i++) {
            int tmp = 0;
            for (int j = 0; j < i; j++) {
                tmp = (tmp * 10) + v[j];
                ans.push_back(tmp);
            }
        }
    } while (next_permutation(v.begin(), v.end()));

    // ������ ���� ans �迭 ����
    sort(ans.begin(), ans.end());

    // �ߺ��� ���� ����
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
}

//int solution(string numbers) {
//    int answer = 0;
//    vector<int> answers;
//
//    // �������� ���������� ������ answers �����̳ʿ� �����ϴ� �Լ�
//    permutationN(numbers, answers);
//
//    // answers �����̳� ���� �Ҽ� ���� Ȯ��
//    for (vector<int>::iterator iter = answers.begin(); iter < answers.end(); ++iter)
//        if (chk(*iter)) answer++;
//
//    return answer;
//}