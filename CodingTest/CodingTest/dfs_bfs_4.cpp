/*
������
���� ����
�־��� �װ����� ��� �̿��Ͽ� �����θ� ¥���� �մϴ�. �׻� "ICN" ���׿��� ����մϴ�.

�װ��� ������ ��� 2���� �迭 tickets�� �Ű������� �־��� ��, �湮�ϴ� ���� ��θ� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
��� ������ ���ĺ� �빮�� 3���ڷ� �̷�����ϴ�.
�־��� ���� ���� 3�� �̻� 10,000�� �����Դϴ�.
tickets�� �� �� [a, b]�� a ���׿��� b �������� ���� �װ����� �ִٴ� �ǹ��Դϴ�.
�־��� �װ����� ��� ����ؾ� �մϴ�.
���� ������ ��ΰ� 2�� �̻��� ��� ���ĺ� ������ �ռ��� ��θ� return �մϴ�.
��� ���ø� �湮�� �� ���� ���� �־����� �ʽ��ϴ�.
����� ��
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
	// �湮 ���� ����
	_visited[_index] = true;

	// root ����
	_root.push_back(_tickets[_index][1]);

	// ��� ��� �湮�ߴ��� �˻�
	if (_root.size() == _tickets.size() + 1)
	{
		// ��� ��带 �湮������ ������̴�.
		if (_result_out.empty())
			_result_out = _root;
		else // �̹� ������� ������ ���, ���ĺ� �� ��
		{
			for (int i = 0; i < _root.size(); ++i)
			{
				// ���ĺ� ���� �ռ��� ���� root �� ��ü�Ѵ�.
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

	// ���� Ƽ�� �� ���� Ƽ���� �������� ������� ��ġ�ϴ� Ƽ�� Ž��
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

	// ���� ������ ����
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