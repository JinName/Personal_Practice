/*
여행경로
문제 설명
주어진 항공권을 모두 이용하여 여행경로를 짜려고 합니다. 항상 "ICN" 공항에서 출발합니다.

항공권 정보가 담긴 2차원 배열 tickets가 매개변수로 주어질 때, 방문하는 공항 경로를 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한사항
모든 공항은 알파벳 대문자 3글자로 이루어집니다.
주어진 공항 수는 3개 이상 10,000개 이하입니다.
tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.
주어진 항공권은 모두 사용해야 합니다.
만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
모든 도시를 방문할 수 없는 경우는 주어지지 않습니다.
입출력 예
tickets																				return
[["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]									["ICN", "JFK", "HND", "IAD"]
[["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]		["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"]
*/

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void DFS(int _index, vector<vector<string>> _tickets, vector<bool> _visited, vector<string> _root, vector<string>& _result_out)
{
	// 방문 상태 갱신
	_visited[_index] = true;

	// root 갱신
	_root.push_back(_tickets[_index][1]);

	// 모든 노드 방문했는지 검사
	if (_root.size() == _tickets.size() + 1)
	{
		// 모든 노드를 방문했으면 결과값이다.
		if (_result_out.empty())
			_result_out = _root;
		else // 이미 결과값이 존재할 경우, 알파벳 순 비교
		{
			for (int i = 0; i < _root.size(); ++i)
			{
				// 알파벳 순이 앞서면 현재 root 로 교체한다.
				if (_root[i] < _result_out[i])
				{
					_result_out = _root;
					break;
				}
				else if (_root[i] > _result_out[i])
					break;
			}
		}

		return;
	}

	// 남은 티켓 중 현재 티켓의 도착지와 출발지가 일치하는 티켓 탐색
	for (int i = 0; i < _tickets.size(); ++i)
	{
		if(_visited[i] == false)
		{ 
			if (_tickets[_index][1] == _tickets[i][0])
			{
				DFS(i, _tickets, _visited, _root, _result_out);
			}
		}		
	}
}

vector<string> solution(vector<vector<string>> tickets)
{
	vector<string> answer;
	vector<string> root;
	vector<bool> visited(tickets.size(), false);

	// 시작 지점은 고정
	root.push_back("ICN");

	for (int i = 0; i < tickets.size(); ++i)
	{
		if (tickets[i][0].compare("ICN") == 0)
			DFS(i, tickets, visited, root, answer);
	}	

	return answer;
}

//int main()
//{
//
//	vector<string> result = solution({ {"ICN", "B"},{"B", "ICN"},{"ICN", "A"}, {"A", "D"}, {"D", "A"} });
//
//	for (auto& elem : result)
//	{
//		cout << elem << " ";
//	}
//
//	cout << endl;
//
//	return 0;
//}