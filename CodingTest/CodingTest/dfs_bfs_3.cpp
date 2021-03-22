/*
�ܾ� ��ȯ
���� ����
�� ���� �ܾ� begin, target�� �ܾ��� ���� words�� �ֽ��ϴ�. �Ʒ��� ���� ��Ģ�� �̿��Ͽ� begin���� target���� ��ȯ�ϴ� ���� ª�� ��ȯ ������ ã������ �մϴ�.

1. �� ���� �� ���� ���ĺ��� �ٲ� �� �ֽ��ϴ�.
2. words�� �ִ� �ܾ�θ� ��ȯ�� �� �ֽ��ϴ�.
���� ��� begin�� "hit", target�� "cog", words�� ["hot","dot","dog","lot","log","cog"]��� "hit" -> "hot" -> "dot" -> "dog" -> "cog"�� ���� 4�ܰ踦 ���� ��ȯ�� �� �ֽ��ϴ�.

�� ���� �ܾ� begin, target�� �ܾ��� ���� words�� �Ű������� �־��� ��, �ּ� �� �ܰ��� ������ ���� begin�� target���� ��ȯ�� �� �ִ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
�� �ܾ�� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
�� �ܾ��� ���̴� 3 �̻� 10 �����̸� ��� �ܾ��� ���̴� �����ϴ�.
words���� 3�� �̻� 50�� ������ �ܾ ������ �ߺ��Ǵ� �ܾ�� �����ϴ�.
begin�� target�� ���� �ʽ��ϴ�.
��ȯ�� �� ���� ��쿡�� 0�� return �մϴ�.
����� ��
begin	target	words										return
"hit"	"cog"	["hot", "dot", "dog", "lot", "log", "cog"]	4
"hit"	"cog"	["hot", "dot", "dog", "lot", "log"]			0
*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// �ʺ� �켱 Ž��(bfs)�� Ȱ��
// ���� : �ѹ��� ���ĺ��� �Ѱ��� �ٲ� �� �ִٴ� ������ �ֱ⶧����, ���ĺ� �ϳ� ���� ��� �ڸ��� ���� �ܾ� �߿� �������� �����ؾ��Ѵ�.
// ��, Ư�� �ܾ�鸸 ���Ἲ�� ������ ������, ����� ������ Ž���ϸ� ������ ��� Ž�� Ƚ���� Ȯ���ϴ� ���� ����Ʈ��� �����ߴ�.

// ���� �켱 Ž��(dfs)�� Ȱ��
// ���� : target ���� �����ϴ� ��� ����� ���� ª�� ���̸� ���ؾ��ϱ⶧����
// ��� Ž���� �� �ʿ䰡 �ִٴ� ������ �����.

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

	// ���̰�
	int depth = 0;

	// ��������� ���� vector
	vector<int> result_arr;

	// �湮 ���� vector
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