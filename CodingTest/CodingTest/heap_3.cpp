/*
���߿켱����ť

���� ����
���� �켱���� ť�� ���� ������ �� �� �ִ� �ڷᱸ���� ���մϴ�.

��ɾ�	���� ž(����)
I ����	ť�� �־��� ���ڸ� �����մϴ�.
D 1	ť���� �ִ��� �����մϴ�.
D -1	ť���� �ּڰ��� �����մϴ�.
���� �켱���� ť�� �� ���� operations�� �Ű������� �־��� ��, ��� ������ ó���� �� ť�� ��������� [0,0] ������� ������ [�ִ�, �ּڰ�]�� return �ϵ��� solution �Լ��� �������ּ���.

���ѻ���
operations�� ���̰� 1 �̻� 1,000,000 ������ ���ڿ� �迭�Դϴ�.
operations�� ���Ҵ� ť�� ������ ������ ��Ÿ���ϴ�.
���Ҵ� ����ɾ� �����͡� �������� �־����ϴ�.- �ִ�/�ּڰ��� �����ϴ� ���꿡�� �ִ�/�ּڰ��� �� �̻��� ���, �ϳ��� �����մϴ�.
�� ť�� �����͸� �����϶�� ������ �־��� ���, �ش� ������ �����մϴ�.
����� ��
operations	return
["I 16","D 1"]	[0,0]
["I 7","I 5","I -5","D -1"]	[7,5]
����� �� ����
16�� ���� �� �ִ��� �����մϴ�. ��������Ƿ� [0,0]�� ��ȯ�մϴ�.
7,5,-5�� ���� �� �ּڰ��� �����մϴ�. �ִ밪 7, �ּҰ� 5�� ��ȯ�մϴ�.
*/


// �켱���� ť�� 2�� ����
// �ִ� �ּҸ� �����ϵ��� �ϰ�, 
// ������ ������ ���� ���� �ּҿ��Ұ����� ���� ť�� ���� ������ �������� ť�� �����Ѵ�.

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;

    int que_cnt = 0;

    for (auto& oper : operations)
    {
        string command = oper.substr(0, 1);
        string data = oper.substr(2);

        int idata = stoi(data);

        if (command.compare("I") == 0)
        {
            max_pq.push(idata);
            min_pq.push(idata);

            ++que_cnt;
        }
        else if (command.compare("D") == 0)
        {
            if (que_cnt > 0)
            {
                if (idata == 1)
                {
                    max_pq.pop();
                }
                else if (idata == -1)
                {
                    min_pq.pop();
                }

                --que_cnt;
            }
        }

        if (que_cnt == 0)
        {
            max_pq = priority_queue<int>();
            min_pq = priority_queue<int, vector<int>, greater<int>>();
        }
    }

    if (que_cnt == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else if (que_cnt > 0)
    {
        answer.push_back(max_pq.top());
        answer.push_back(min_pq.top());
    }

    return answer;
}