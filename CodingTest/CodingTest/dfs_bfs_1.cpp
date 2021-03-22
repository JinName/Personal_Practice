/*
Ÿ�� �ѹ�
���� ����
n���� ���� �ƴ� ������ �ֽ��ϴ�. �� ���� ������ ���ϰų� ���� Ÿ�� �ѹ��� ������� �մϴ�. ���� ��� [1, 1, 1, 1, 1]�� ���� 3�� ������� ���� �ټ� ����� �� �� �ֽ��ϴ�.

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
����� �� �ִ� ���ڰ� ��� �迭 numbers, Ÿ�� �ѹ� target�� �Ű������� �־��� �� ���ڸ� ������ ���ϰ� ���� Ÿ�� �ѹ��� ����� ����� ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
�־����� ������ ������ 2�� �̻� 20�� �����Դϴ�.
�� ���ڴ� 1 �̻� 50 ������ �ڿ����Դϴ�.
Ÿ�� �ѹ��� 1 �̻� 1000 ������ �ڿ����Դϴ�.
����� ��
numbers				target		return
[1, 1, 1, 1, 1]		3			5
*/

#include <string>
#include <vector>

using namespace std;

// ���� �켱 Ž��(dfs)�� Ȱ��
// ���ڸ� ����ϴ� ��� ��θ� Ž���ؼ� ������ ��� ++answer
// �Ű������� ���� �迭 index�� �հ� sum �� �Ѱ��ָ鼭 �������� ���������� sum ���� Ȯ���Ѵ�.
void dfs(vector<int> _numbers, int _target, int _start_index, int _sum, int& _answer)
{
	if (_start_index >= _numbers.size())
	{
		if (_sum == _target)
			++_answer;
		
		return;
	}

	dfs(_numbers, _target, _start_index + 1, _sum + _numbers[_start_index], _answer);
	dfs(_numbers, _target, _start_index + 1, _sum - _numbers[_start_index], _answer);
}

int solution(vector<int> numbers, int target)
{
	int answer = 0;

	dfs(numbers, target, 0, 0, answer);

	return answer;
}

//int main()
//{
//	solution({ 1, 1, 1, 1, 1 }, 3);
//
//	return 0;
//}