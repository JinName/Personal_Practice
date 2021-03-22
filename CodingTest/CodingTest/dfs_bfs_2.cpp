/*
네트워크
문제 설명
네트워크란 컴퓨터 상호 간에 정보를 교환할 수 있도록 연결된 형태를 의미합니다. 예를 들어, 컴퓨터 A와 컴퓨터 B가 직접적으로 연결되어있고, 컴퓨터 B와 컴퓨터 C가 직접적으로 연결되어 있을 때 컴퓨터 A와 컴퓨터 C도 간접적으로 연결되어 정보를 교환할 수 있습니다. 따라서 컴퓨터 A, B, C는 모두 같은 네트워크 상에 있다고 할 수 있습니다.

컴퓨터의 개수 n, 연결에 대한 정보가 담긴 2차원 배열 computers가 매개변수로 주어질 때, 네트워크의 개수를 return 하도록 solution 함수를 작성하시오.

제한사항
컴퓨터의 개수 n은 1 이상 200 이하인 자연수입니다.
각 컴퓨터는 0부터 n-1인 정수로 표현합니다.
i번 컴퓨터와 j번 컴퓨터가 연결되어 있으면 computers[i][j]를 1로 표현합니다.
computer[i][i]는 항상 1입니다.
입출력 예
n	computers							return
3	[[1, 1, 0], [1, 1, 0], [0, 0, 1]]	2
3	[[1, 1, 0], [1, 1, 1], [0, 1, 1]]	1
*/


#include <string>
#include <vector>
#include <queue>

using namespace std;

// 너비 우선 탐색(bfs)를 활용.
// 0번 컴퓨터와 연결되어있는 노드부터 탐색하여
// 이미 탐색한 노드는 true 로 전환
// 탐색이 끝나면 그것이 1개의 네트워크로 판별한다.

typedef pair<int, vector<int>> pair_int_vec;

int solution(int n, vector<vector<int>> computers)
{
	int answer = 0;

	// 방문한 노드인지 판별할 변수
	vector<bool> visited(n, false);

	// 연결되어있는 노드들을 큐에 넣고 순차 탐색
	queue<pair_int_vec> visit_que;

	// 노드 탐색 시작
	for (int i = 0; i < n; ++i)
	{
		// 시작 노드 삽입
		if (visited[i] != true)
		{
			visit_que.push(pair_int_vec(i, computers[i]));
		
			while (!visit_que.empty())
			{
				// 큐에서 방문할 노드 pop
				pair_int_vec node = visit_que.front();
				visit_que.pop();

				// 노드 방문 체크
				visited[node.first] = true;

				// 다음 방문할 노드 큐잉
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

			// 노드에 연결된 모든 노드 탐색이 끝나면, 하나의 네트워크에 대한 탐색이 끝난것.
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