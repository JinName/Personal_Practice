/*
��ɰ���

���� ����
���α׷��ӽ� �������� ��� ���� �۾��� ���� ���Դϴ�.�� ����� ������ 100 % �� �� ���񽺿� �ݿ��� �� �ֽ��ϴ�.

��, �� ����� ���߼ӵ��� ��� �ٸ��� ������ �ڿ� �ִ� ����� �տ� �ִ� ��ɺ��� ���� ���ߵ� �� �ְ�, �̶� �ڿ� �ִ� ����� �տ� �ִ� ����� ������ �� �Բ� �����˴ϴ�.

���� �����Ǿ�� �ϴ� ������� �۾��� ������ ���� ���� �迭 progresses�� �� �۾��� ���� �ӵ��� ���� ���� �迭 speeds�� �־��� �� �� �������� �� ���� ����� �����Ǵ����� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���� ����
�۾��� ����(progresses, speeds�迭�� ����)�� 100�� �����Դϴ�.
�۾� ������ 100 �̸��� �ڿ����Դϴ�.
�۾� �ӵ��� 100 ������ �ڿ����Դϴ�.
������ �Ϸ翡 �� ���� �� �� ������, �Ϸ��� ���� �̷�����ٰ� �����մϴ�.���� ��� �������� 95 % �� �۾��� ���� �ӵ��� �Ϸ翡 4 % ��� ������ 2�� �ڿ� �̷�����ϴ�.
����� ��
progresses	speeds	return
[93, 30, 55][1, 30, 5][2, 1]
[95, 90, 99, 99, 80, 99][1, 1, 1, 1, 1, 1][1, 3, 2]
����� �� ����
����� �� #1
ù ��° ����� 93 % �Ϸ�Ǿ� �ְ� �Ϸ翡 1 % �� �۾��� �����ϹǷ� 7�ϰ� �۾� �� ������ �����մϴ�.
�� ��° ����� 30 % �� �Ϸ�Ǿ� �ְ� �Ϸ翡 30 % �� �۾��� �����ϹǷ� 3�ϰ� �۾� �� ������ �����մϴ�.������ ���� ù ��° ����� ���� �ϼ��� ���°� �ƴϱ� ������ ù ��° ����� �����Ǵ� 7��° �����˴ϴ�.
�� ��° ����� 55 % �� �Ϸ�Ǿ� �ְ� �Ϸ翡 5 % �� �۾��� �����ϹǷ� 9�ϰ� �۾� �� ������ �����մϴ�.

���� 7��°�� 2���� ���, 9��°�� 1���� ����� �����˴ϴ�.

����� �� #2
��� ����� �Ϸ翡 1 % �� �۾��� �����ϹǷ�, �۾��� ��������� ���� �ϼ��� ���� 5��, 10��, 1��, 1��, 20��, 1���Դϴ�.� ����� ���� �ϼ��Ǿ����� �տ� �ִ� ��� ����� �ϼ����� ������ ������ �Ұ����մϴ�.

���� 5��°�� 1���� ���, 10��°�� 3���� ���, 20��°�� 2���� ����� �����˴ϴ�.
*/

#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    stack<int> s;
    vector<int> complete_date;

    for (int i = 0; i < progresses.size(); ++i)
    {
        float fdate = (100.0f - (float)progresses[i]) / (float)speeds[i];
        int idate = (int)fdate;

        int result_date = fdate > idate ? idate + 1 : idate;

        complete_date.push_back(result_date);
    }

    for (int i = complete_date.size() - 1; i >= 0; --i)
    {
        s.push(complete_date.back());
        complete_date.pop_back();
    }

    int curr = s.top();
    int cnt = 0;
    int size = s.size();

    for (int i = 0; i < size; ++i)
    {
        if (curr < s.top())
        {
            answer.push_back(cnt);
            curr = s.top();
            s.pop();
            cnt = 1;
        }
        else
        {
            ++cnt;
            s.pop();
        }
    }
    answer.push_back(cnt);

    return answer;
}

//void main()
//{
//    vector<int> con = solution({ 93, 30, 50 }, { 1, 30, 5 });
//
//    for (auto& elem : con)
//    {
//        cout << elem << endl;
//    }
//}