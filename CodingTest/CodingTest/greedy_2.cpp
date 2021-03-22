/*
���̽�ƽ
���� ����
���̽�ƽ���� ���ĺ� �̸��� �ϼ��ϼ���. �� ó���� A�θ� �̷���� �ֽ��ϴ�.
ex) �ϼ��ؾ� �ϴ� �̸��� �� ���ڸ� AAA, �� ���ڸ� AAAA

���̽�ƽ�� �� �������� �����̸� �Ʒ��� �����ϴ�.

�� - ���� ���ĺ�
�� - ���� ���ĺ� (A���� �Ʒ������� �̵��ϸ� Z��)
�� - Ŀ���� �������� �̵� (ù ��° ��ġ���� �������� �̵��ϸ� ������ ���ڿ� Ŀ��)
�� - Ŀ���� ���������� �̵�
���� ��� �Ʒ��� ������� "JAZ"�� ���� �� �ֽ��ϴ�.

- ù ��° ��ġ���� ���̽�ƽ�� ���� 9�� �����Ͽ� J�� �ϼ��մϴ�.
- ���̽�ƽ�� �������� 1�� �����Ͽ� Ŀ���� ������ ���� ��ġ�� �̵���ŵ�ϴ�.
- ������ ��ġ���� ���̽�ƽ�� �Ʒ��� 1�� �����Ͽ� Z�� �ϼ��մϴ�.
���� 11�� �̵����� "JAZ"�� ���� �� �ְ�, �̶��� �ּ� �̵��Դϴ�.
������� �ϴ� �̸� name�� �Ű������� �־��� ��, �̸��� ���� ���̽�ƽ ���� Ƚ���� �ּڰ��� return �ϵ��� solution �Լ��� ���弼��.

���� ����
name�� ���ĺ� �빮�ڷθ� �̷���� �ֽ��ϴ�.
name�� ���̴� 1 �̻� 20 �����Դϴ�.
����� ��
name	    return
"JEROEN"	56
"JAN"	    23
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

// pair<�����Ÿ�, ��Ʈ>
typedef pair<int, vector<int>> pair_int;

void dfs(int _start_index, vector<int> _node_indexs, priority_queue<pair_int, vector<pair_int>, greater<pair_int>>& _pq)
{
    int curr_index = _node_indexs.front();

    for(int i = 0; i < _node_indexs.size(); i++)
    {

    }
}

int solution(string name) {
    int answer = 0;

    // 1. ������� ������ �ʿ����� üũ
    // 2. ������ �ʿ��ϴٸ�, ���ϴ� ���ڱ��� �ִܰŸ� Ȯ��
    // 3. ������ �ʿ��� ���ڱ����� �̵� �Ÿ� ���

    vector<int> node_indexs;
    priority_queue<pair_int, vector<pair_int>, greater<pair_int>> pq;

    // Ž���ؾ��ϴ� node index Ȯ��
    // ������ ����
    node_indexs.push_back(0);

    for (int i = 1; i < name.length(); ++i)
    {
        if (name.at(i) != 'A')
        {
            node_indexs.push_back(i);
        }
    }

    int curr = 0;

    for (int i = 0; i < name.length(); ++i)
    {
        // 1. ������ �ʿ����� üũ
        if (name.at(i) != 'A')
        {
            // 2. ������ �ʿ��ϴٸ�, �����Ϸ��� ��ġ���� �ִܰŸ� Ȯ��
            answer += (i - curr) < (curr + 1) ? i - curr : curr + 1;

            // 3. �����Ϸ��� ��ġ�� �����ϸ�, ���ϴ� ���ڱ����� �ִܰŸ� ���
            answer += (name.at(i) - 'A') < ('Z' + 1 - name.at(i)) ? (name.at(i) - 'A') : ('Z' + 1 - name.at(i));

            curr = i;
        }
    }

    return answer;
}