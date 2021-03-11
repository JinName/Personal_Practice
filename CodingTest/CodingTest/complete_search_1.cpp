/*
���ǰ��

���� ����
�����ڴ� ������ ������ ����� �ظ��Դϴ�. ������ ���ι��� ���ǰ�翡 ���� ������ ���� ������ �մϴ�. �����ڴ� 1�� �������� ������ �������� ������ ���� ����ϴ�.

1�� �����ڰ� ��� ���: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2�� �����ڰ� ��� ���: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3�� �����ڰ� ��� ���: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1�� �������� ������ ���������� ������ ������� ���� �迭 answers�� �־����� ��, ���� ���� ������ ���� ����� �������� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���� ����
������ �ִ� 10,000 ������ �����Ǿ��ֽ��ϴ�.
������ ������ 1, 2, 3, 4, 5�� �ϳ��Դϴ�.
���� ���� ������ ���� ����� ������ ���, return�ϴ� ���� �������� �������ּ���.
����� ��
answers	return
[1,2,3,4,5]	[1]
[1,3,2,4,2]	[1,2,3]
����� �� ����
����� �� #1

������ 1�� ��� ������ �������ϴ�.
������ 2�� ��� ������ Ʋ�Ƚ��ϴ�.
������ 3�� ��� ������ Ʋ�Ƚ��ϴ�.
���� ���� ������ ���� ���� ����� ������ 1�Դϴ�.

����� �� #2

��� ����� 2�������� ������ϴ�.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> sorted_player;

    vector<int> player1 = { 1, 2, 3, 4, 5 };
    vector<int> player2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> player3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    vector<pair<int, int>> result = { {1, 0}, {2, 0}, {3, 0} };

    for (int i = 0; i < answers.size(); ++i)
    {
        if (player1[i % player1.size()] == answers[i])
            ++result[0].second;
        if (player2[i % player2.size()] == answers[i])
            ++result[1].second;
        if (player3[i % player3.size()] == answers[i])
            ++result[2].second;
    }

    sort(result.begin(), result.end(), [](pair<int, int> _a, pair<int, int> _b)->bool {
        return _a.second > _b.second;
        });

    sorted_player.push_back(result[0].first);

    for (int i = 1; i < result.size(); ++i)
    {
        if (result[i].second == result[0].second)
            sorted_player.push_back(result[i].first);
        else
            break;
    }

    if (sorted_player.size() > 1)
        sort(sorted_player.begin(), sorted_player.end());

    return sorted_player;
}