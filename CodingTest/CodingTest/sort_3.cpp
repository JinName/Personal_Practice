/*
H-Index

���� ����
H-Index�� �������� ���꼺�� ������� ��Ÿ���� ��ǥ�Դϴ�. ��� �������� H-Index�� ��Ÿ���� ���� h�� ���Ϸ��� �մϴ�. ��Ű���1�� ������, H-Index�� ������ ���� ���մϴ�.

� �����ڰ� ��ǥ�� �� n�� ��, h�� �̻� �ο�� ���� h�� �̻��̰� ������ ���� h�� ���� �ο�Ǿ��ٸ� h�� �ִ��� �� �������� H-Index�Դϴ�.

� �����ڰ� ��ǥ�� ���� �ο� Ƚ���� ���� �迭 citations�� �Ű������� �־��� ��, �� �������� H-Index�� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
�����ڰ� ��ǥ�� ���� ���� 1�� �̻� 1,000�� �����Դϴ�.
���� �ο� Ƚ���� 0ȸ �̻� 10,000ȸ �����Դϴ�.
����� ��
citations	return
[3, 0, 6, 1, 5]	3
����� �� ����
�� �����ڰ� ��ǥ�� ���� ���� 5���̰�, ���� 3���� ���� 3ȸ �̻� �ο�Ǿ����ϴ�. �׸��� ������ 2���� ���� 3ȸ ���� �ο�Ǿ��� ������ �� �������� H-Index�� 3�Դϴ�.

�� ���� - 2019�� 2�� 28�� �׽�Ʈ ���̽��� �߰��Ǿ����ϴ�.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    int right_cnt = 0;

    sort(citations.begin(), citations.end());

    if (citations[citations.size() - 1] == 0)
        return 0;

    for (int i = 0; i < citations.size(); ++i)
    {
        right_cnt = citations.size() - i;

        if (citations[i] >= right_cnt)
            break;
    }

    answer = right_cnt;

    return answer;
}