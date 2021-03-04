/*
���� ����
��Ʈ���� ����Ʈ���� �帣 ���� ���� ���� ����� �뷡�� �� ���� ��� ����Ʈ �ٹ��� ����Ϸ� �մϴ�.�뷡�� ���� ��ȣ�� �����ϸ�, �뷡�� �����ϴ� ������ ������ �����ϴ�.

���� �뷡�� ���� ����� �帣�� ���� �����մϴ�.
�帣 ������ ���� ����� �뷡�� ���� �����մϴ�.
�帣 ������ ��� Ƚ���� ���� �뷡 �߿����� ���� ��ȣ�� ���� �뷡�� ���� �����մϴ�.
�뷡�� �帣�� ��Ÿ���� ���ڿ� �迭 genres�� �뷡�� ��� Ƚ���� ��Ÿ���� ���� �迭 plays�� �־��� ��, ����Ʈ �ٹ��� �� �뷡�� ���� ��ȣ�� ������� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���ѻ���
genres[i]�� ������ȣ�� i�� �뷡�� �帣�Դϴ�.
plays[i]�� ������ȣ�� i�� �뷡�� ����� Ƚ���Դϴ�.
genres�� plays�� ���̴� ������, �̴� 1 �̻� 10, 000 �����Դϴ�.
�帣 ������ 100�� �̸��Դϴ�.
�帣�� ���� ���� �ϳ����, �ϳ��� � �����մϴ�.
��� �帣�� ����� Ƚ���� �ٸ��ϴ�.

����� ��

genres	                                        plays	                    return
["classic", "pop", "classic", "classic", "pop"] [500, 600, 150, 800, 2500]  [4, 1, 3, 0]

����� �� ����

classic �帣�� 1, 450ȸ ����Ǿ�����, classic �뷡�� ������ �����ϴ�.

���� ��ȣ 3: 800ȸ ���
���� ��ȣ 0 : 500ȸ ���
���� ��ȣ 2 : 150ȸ ���
pop �帣�� 3, 100ȸ ����Ǿ�����, pop �뷡�� ������ �����ϴ�.

���� ��ȣ 4 : 2, 500ȸ ���
���� ��ȣ 1 : 600ȸ ���
���� pop �帣��[4, 1]�� �뷡�� ����, classic �帣��[3, 0]�� �뷡�� �״����� �����մϴ�.
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef pair<int, int> pair_int;
typedef pair<string, int> string_int;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    // �帣�� �� ��ȣ�� ��� Ƚ���� ���� �����̳�
    unordered_map<string, vector<pair_int>> total;

    // �帣�� �� ��� Ƚ���� ���� �����̳�
    unordered_map<string, int> total_cnt;    

    // �����̳� ����
    for (int i = 0; i < plays.size(); ++i)
    {
        total[genres[i]].push_back(pair_int(plays[i], i));

        if (total_cnt.find(genres[i]) == total_cnt.end())
            total_cnt[genres[i]] = plays[i];
        else
            total_cnt[genres[i]] += plays[i];
    }
    
    // �帣�� �� ��� Ƚ���� ������������ ����
    vector<string_int> total_cnt_vector(total_cnt.begin(), total_cnt.end());
    
    sort(total_cnt_vector.begin(), total_cnt_vector.end(), [](string_int _left, string_int _right) {
        return _left.second > _right.second;
    });

    // �帣�� ����� ��� ���� �������� ����
    for (int i = 0; i < plays.size(); ++i)
    {
        sort(total[genres[i]].begin(), total[genres[i]].end(), [](pair_int _left, pair_int _right) {
            return _left.first > _right.first;
        });
    }

    // �帣 ������ top 2 ����
    for (auto& elem : total_cnt_vector)
    {
        for (int i = 0; i < total[elem.first].size(); ++i)
        {
            answer.push_back(total[elem.first][i].second);

            if (i >= 1)
                break;
        }
    }

    return answer;
}