/*
단어 변환
문제 설명
두 개의 단어 begin, target과 단어의 집합 words가 있습니다. 아래와 같은 규칙을 이용하여 begin에서 target으로 변환하는 가장 짧은 변환 과정을 찾으려고 합니다.

1. 한 번에 한 개의 알파벳만 바꿀 수 있습니다.
2. words에 있는 단어로만 변환할 수 있습니다.
예를 들어 begin이 "hit", target가 "cog", words가 ["hot","dot","dog","lot","log","cog"]라면 "hit" -> "hot" -> "dot" -> "dog" -> "cog"와 같이 4단계를 거쳐 변환할 수 있습니다.

두 개의 단어 begin, target과 단어의 집합 words가 매개변수로 주어질 때, 최소 몇 단계의 과정을 거쳐 begin을 target으로 변환할 수 있는지 return 하도록 solution 함수를 작성해주세요.

제한사항
각 단어는 알파벳 소문자로만 이루어져 있습니다.
각 단어의 길이는 3 이상 10 이하이며 모든 단어의 길이는 같습니다.
words에는 3개 이상 50개 이하의 단어가 있으며 중복되는 단어는 없습니다.
begin과 target은 같지 않습니다.
변환할 수 없는 경우에는 0를 return 합니다.
입출력 예
begin	target	words										return
"hit"	"cog"	["hot", "dot", "dog", "lot", "log", "cog"]	4
"hit"	"cog"	["hot", "dot", "dog", "lot", "log"]			0
*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 너비 우선 탐색(bfs)을 활용
// 이유 : 한번에 알파벳을 한개만 바꿀 수 있다는 조건이 있기때문에, 알파벳 하나 빼고 모든 자리가 같은 단어 중에 갈림길을 선택해야한다.
// 즉, 특정 단어들만 연결성을 가지고 있으며, 연결된 노드들을 탐색하며 정답일 경우 탐색 횟수를 확인하는 것이 포인트라고 생각했다.

// 깊이 우선 탐색(dfs)을 활용
// 이유 : target 까지 도착하는 모든 경로중 가장 짧은 길이를 구해야하기때문에
// 모든 탐색을 할 필요가 있다는 생각이 들었다.

bool check_word(string _curr_str, string _target_str)
{
	int diff_cnt = 0;

	for (int i = 0; i < _curr_str.length(); ++i)
	{
		if (_curr_str[i] != _target_str[i])
		{
			++diff_cnt;
		}

		if (diff_cnt > 1)
			return false;
	}

	return true;
}

void dfs_words(string _begin, string _target, vector<string> _words, int _curr_index, int _depth, vector<bool>& _visited, vector<int>& _result)
{
	_visited[_curr_index] = true;

	if (_begin.compare(_target) == 0)
	{
		_result.push_back(_depth);

		return;
	}

	for (int i = 0; i < _words.size(); ++i)
	{
		if (_visited[i] == false)
		{
			if (check_word(_begin, _words[i]))
			{
				_begin = _words[i];
				dfs_words(_begin, _target, _words, i, _depth + 1, _visited, _result);
			}
		}
	}
}

int solution(string begin, string target, vector<string> words)
{
	int answer = 0;

	// 깊이값
	int depth = 0;

	// 결과값들을 담을 vector
	vector<int> result_arr;

	// 방문 상태 vector
	vector<bool> visited(words.size(), false);

	for (int i = 0; i < words.size(); ++i)
	{
		if (check_word(begin, words[i]))
		{
			dfs_words(words[i], target, words, i, 1, visited, result_arr);
		}
	}	

	if (!result_arr.empty())
	{
		sort(result_arr.begin(), result_arr.end());

		answer = result_arr[0];
	}
		
	return answer;
}

//int main()
//{
//	int result = solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
//
//	return 0;
//}