/*
타겟 넘버
문제 설명
n개의 음이 아닌 정수가 있습니다. 이 수를 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다. 예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성해주세요.

제한사항
주어지는 숫자의 개수는 2개 이상 20개 이하입니다.
각 숫자는 1 이상 50 이하인 자연수입니다.
타겟 넘버는 1 이상 1000 이하인 자연수입니다.
입출력 예
numbers				target		return
[1, 1, 1, 1, 1]		3			5
*/

#include <string>
#include <vector>

using namespace std;

// 깊이 우선 탐색(dfs)을 활용
// 숫자를 계산하는 모든 경로를 탐색해서 정답일 경우 ++answer
// 매개변수로 다음 배열 index와 합계 sum 을 넘겨주면서 마지막에 도달했을때 sum 값을 확인한다.
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