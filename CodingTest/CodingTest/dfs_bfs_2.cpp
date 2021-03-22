/*
��Ʈ��ũ
���� ����
��Ʈ��ũ�� ��ǻ�� ��ȣ ���� ������ ��ȯ�� �� �ֵ��� ����� ���¸� �ǹ��մϴ�. ���� ���, ��ǻ�� A�� ��ǻ�� B�� ���������� ����Ǿ��ְ�, ��ǻ�� B�� ��ǻ�� C�� ���������� ����Ǿ� ���� �� ��ǻ�� A�� ��ǻ�� C�� ���������� ����Ǿ� ������ ��ȯ�� �� �ֽ��ϴ�. ���� ��ǻ�� A, B, C�� ��� ���� ��Ʈ��ũ �� �ִٰ� �� �� �ֽ��ϴ�.

��ǻ���� ���� n, ���ῡ ���� ������ ��� 2���� �迭 computers�� �Ű������� �־��� ��, ��Ʈ��ũ�� ������ return �ϵ��� solution �Լ��� �ۼ��Ͻÿ�.

���ѻ���
��ǻ���� ���� n�� 1 �̻� 200 ������ �ڿ����Դϴ�.
�� ��ǻ�ʹ� 0���� n-1�� ������ ǥ���մϴ�.
i�� ��ǻ�Ϳ� j�� ��ǻ�Ͱ� ����Ǿ� ������ computers[i][j]�� 1�� ǥ���մϴ�.
computer[i][i]�� �׻� 1�Դϴ�.
����� ��
n	computers							return
3	[[1, 1, 0], [1, 1, 0], [0, 0, 1]]	2
3	[[1, 1, 0], [1, 1, 1], [0, 1, 1]]	1
*/


#include <string>
#include <vector>
#include <queue>

using namespace std;

// �ʺ� �켱 Ž��(bfs)�� Ȱ��.
// 0�� ��ǻ�Ϳ� ����Ǿ��ִ� ������ Ž���Ͽ�
// �̹� Ž���� ���� true �� ��ȯ
// Ž���� ������ �װ��� 1���� ��Ʈ��ũ�� �Ǻ��Ѵ�.

typedef pair<int, vector<int>> pair_int_vec;

int solution(int n, vector<vector<int>> computers)
{
	int answer = 0;

	// �湮�� ������� �Ǻ��� ����
	vector<bool> visited(n, false);

	// ����Ǿ��ִ� ������ ť�� �ְ� ���� Ž��
	queue<pair_int_vec> visit_que;

	// ��� Ž�� ����
	for (int i = 0; i < n; ++i)
	{
		// ���� ��� ����
		if (visited[i] != true)
		{
			visit_que.push(pair_int_vec(i, computers[i]));
		
			while (!visit_que.empty())
			{
				// ť���� �湮�� ��� pop
				pair_int_vec node = visit_que.front();
				visit_que.pop();

				// ��� �湮 üũ
				visited[node.first] = true;

				// ���� �湮�� ��� ť��
				for (int j = 0; j < node.second.size(); ++j)
				{
					if (visited[j] != true && j != node.first)
					{
						if (node.second[j] == 1)
						{
							visit_que.push(pair_int_vec(j, computers[j]));
						}
					}
				}
			}

			// ��忡 ����� ��� ��� Ž���� ������, �ϳ��� ��Ʈ��ũ�� ���� Ž���� ������.
			// answer + 1
			++answer;
		}	
	}	

	return answer;
}

//int main()
//{
//	solution(3, { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} });
//
//	return 0;
//}