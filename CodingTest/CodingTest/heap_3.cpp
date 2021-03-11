/*
이중우선순위큐

문제 설명
이중 우선순위 큐는 다음 연산을 할 수 있는 자료구조를 말합니다.

명령어	수신 탑(높이)
I 숫자	큐에 주어진 숫자를 삽입합니다.
D 1	큐에서 최댓값을 삭제합니다.
D -1	큐에서 최솟값을 삭제합니다.
이중 우선순위 큐가 할 연산 operations가 매개변수로 주어질 때, 모든 연산을 처리한 후 큐가 비어있으면 [0,0] 비어있지 않으면 [최댓값, 최솟값]을 return 하도록 solution 함수를 구현해주세요.

제한사항
operations는 길이가 1 이상 1,000,000 이하인 문자열 배열입니다.
operations의 원소는 큐가 수행할 연산을 나타냅니다.
원소는 “명령어 데이터” 형식으로 주어집니다.- 최댓값/최솟값을 삭제하는 연산에서 최댓값/최솟값이 둘 이상인 경우, 하나만 삭제합니다.
빈 큐에 데이터를 삭제하라는 연산이 주어질 경우, 해당 연산은 무시합니다.
입출력 예
operations	return
["I 16","D 1"]	[0,0]
["I 7","I 5","I -5","D -1"]	[7,5]
입출력 예 설명
16을 삽입 후 최댓값을 삭제합니다. 비어있으므로 [0,0]을 반환합니다.
7,5,-5를 삽입 후 최솟값을 삭제합니다. 최대값 7, 최소값 5를 반환합니다.
*/


// 우선순위 큐를 2개 만들어서
// 최대 최소를 관리하도록 하고, 
// 원소의 삭제에 따라 둘중 최소원소갯수를 가진 큐의 원소 갯수를 기준으로 큐를 정리한다.

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;

    int que_cnt = 0;

    for (auto& oper : operations)
    {
        string command = oper.substr(0, 1);
        string data = oper.substr(2);

        int idata = stoi(data);

        if (command.compare("I") == 0)
        {
            max_pq.push(idata);
            min_pq.push(idata);

            ++que_cnt;
        }
        else if (command.compare("D") == 0)
        {
            if (que_cnt > 0)
            {
                if (idata == 1)
                {
                    max_pq.pop();
                }
                else if (idata == -1)
                {
                    min_pq.pop();
                }

                --que_cnt;
            }
        }

        if (que_cnt == 0)
        {
            max_pq = priority_queue<int>();
            min_pq = priority_queue<int, vector<int>, greater<int>>();
        }
    }

    if (que_cnt == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else if (que_cnt > 0)
    {
        answer.push_back(max_pq.top());
        answer.push_back(min_pq.top());
    }

    return answer;
}