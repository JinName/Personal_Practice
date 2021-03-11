/*
��ũ ��Ʈ�ѷ�

���� ����
�ϵ��ũ�� �� ���� �ϳ��� �۾��� ������ �� �ֽ��ϴ�. ��ũ ��Ʈ�ѷ��� �����ϴ� ����� ���� ������ �ֽ��ϴ�. ���� �Ϲ����� ����� ��û�� ���� ������� ó���ϴ� ���Դϴ�.

�������

- 0ms ������ 3ms�� �ҿ�Ǵ� A�۾� ��û
- 1ms ������ 9ms�� �ҿ�Ǵ� B�۾� ��û
- 2ms ������ 6ms�� �ҿ�Ǵ� C�۾� ��û
�� ���� ��û�� ���Խ��ϴ�. �̸� �׸����� ǥ���ϸ� �Ʒ��� �����ϴ�.
Screen Shot 2018-09-13 at 6.34.58 PM.png

�� ���� �ϳ��� ��û���� ������ �� �ֱ� ������ ������ �۾��� ��û���� ������� ó���ϸ� ������ ���� ó�� �˴ϴ�.
Screen Shot 2018-09-13 at 6.38.52 PM.png

- A: 3ms ������ �۾� �Ϸ� (��û���� ������� : 3ms)
- B: 1ms���� ����ϴٰ�, 3ms ������ �۾��� �����ؼ� 12ms ������ �۾� �Ϸ�(��û���� ������� : 11ms)
- C: 2ms���� ����ϴٰ�, 12ms ������ �۾��� �����ؼ� 18ms ������ �۾� �Ϸ�(��û���� ������� : 16ms)
�� �� �� �۾��� ��û���� ������� �ɸ� �ð��� ����� 10ms(= (3 + 11 + 16) / 3)�� �˴ϴ�.

������ A �� C �� B ������� ó���ϸ�
Screen Shot 2018-09-13 at 6.41.42 PM.png

- A: 3ms ������ �۾� �Ϸ�(��û���� ������� : 3ms)
- C: 2ms���� ����ϴٰ�, 3ms ������ �۾��� �����ؼ� 9ms ������ �۾� �Ϸ�(��û���� ������� : 7ms)
- B: 1ms���� ����ϴٰ�, 9ms ������ �۾��� �����ؼ� 18ms ������ �۾� �Ϸ�(��û���� ������� : 17ms)
�̷��� A �� C �� B�� ������ ó���ϸ� �� �۾��� ��û���� ������� �ɸ� �ð��� ����� 9ms(= (3 + 7 + 17) / 3)�� �˴ϴ�.

�� �۾��� ���� [�۾��� ��û�Ǵ� ����, �۾��� �ҿ�ð�]�� ���� 2���� �迭 jobs�� �Ű������� �־��� ��, �۾��� ��û���� ������� �ɸ� �ð��� ����� ���� ���̴� ������� ó���ϸ� ����� �󸶰� �Ǵ��� return �ϵ��� solution �Լ��� �ۼ����ּ���. (��, �Ҽ��� ������ ���� �����ϴ�)

���� ����
jobs�� ���̴� 1 �̻� 500 �����Դϴ�.
jobs�� �� ���� �ϳ��� �۾��� ���� [�۾��� ��û�Ǵ� ����, �۾��� �ҿ�ð�] �Դϴ�.
�� �۾��� ���� �۾��� ��û�Ǵ� �ð��� 0 �̻� 1,000 �����Դϴ�.
�� �۾��� ���� �۾��� �ҿ�ð��� 1 �̻� 1,000 �����Դϴ�.
�ϵ��ũ�� �۾��� �����ϰ� ���� ���� ������ ���� ��û�� ���� �۾����� ó���մϴ�.
����� ��
jobs	return
[[0, 3], [1, 9], [2, 6]]	9
����� �� ����
������ �־��� ���� �����ϴ�.

0ms ������ 3ms �ɸ��� �۾� ��û�� ���ɴϴ�.
1ms ������ 9ms �ɸ��� �۾� ��û�� ���ɴϴ�.
2ms ������ 6ms �ɸ��� �۾� ��û�� ���ɴϴ�.
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

// ������ ó���ð��� ª�� �ͺ��� ó���ؾ� ��� ó���ð��� �پ���.
// ������ ���� �ͺ��� ó���� �����ϰ�,
// �ش� �۾��� ó���ð� ���� ��û�� ������ �۾��鿡 ���� ó���ð��� ª�� �ͺ��� ó���Ѵ�.
// ���� ���� ���� �۾� �ð� ���� ��ġ�� ��û �߿� ���� ó���� �۾��� ���� �����ؾ� ��.

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    int time = 0;
    int time_stack = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> low_pair_pq;
    queue<pair<int, int>> temp_que;
    pair<int, int> next_task;

    // �켱���� ť�� ����
    for (auto& elem : jobs)
    {
        low_pair_pq.push({ elem[0], elem[1] });
    }

    next_task = low_pair_pq.top();
    low_pair_pq.pop();
    time += next_task.first;

    while (!low_pair_pq.empty())
    {
        // ���� �۾� �Ϸ� �ð�
        time += next_task.second;
        time_stack += time - next_task.first;

        if (!low_pair_pq.empty())
        {
            next_task = low_pair_pq.top();
            low_pair_pq.pop();

            // ó�� �ð� ���� ��û �۾� �� �� ª�� ó�� �ð��� next_task �� �����Ѵ�.
            // next_task ���� Ż���� �͵��� temp_que �� ��Ƴ��Ҵٰ� �켱���� ť�� �ٽ� ����.

            while (!low_pair_pq.empty() && low_pair_pq.top().first < time)
            {
                pair<int, int> temp_task = low_pair_pq.top();
                low_pair_pq.pop();

                if (temp_task.second > next_task.second)
                {
                    temp_que.push(temp_task);
                }
                else
                {
                    temp_que.push(next_task);
                    next_task = temp_task;
                }
            }

            // �񱳰� ������ �ӽ� ť -> �켱���� ť �ٽ� ����
            int size = temp_que.size();
            for (int i = 0; i < size; ++i)
            {
                pair<int, int> temp_task = temp_que.front();
                temp_que.pop();

                low_pair_pq.push(temp_task);
            }
        }
    }

    // ������ �۾� ó�� �ð� ���
    time += next_task.second;
    time_stack += time - next_task.first;

    // ��û ó�� �ð� ��հ� ���
    answer = time_stack / jobs.size();

    return answer;
}