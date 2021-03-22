/*
조이스틱
문제 설명
조이스틱으로 알파벳 이름을 완성하세요. 맨 처음엔 A로만 이루어져 있습니다.
ex) 완성해야 하는 이름이 세 글자면 AAA, 네 글자면 AAAA

조이스틱을 각 방향으로 움직이면 아래와 같습니다.

▲ - 다음 알파벳
▼ - 이전 알파벳 (A에서 아래쪽으로 이동하면 Z로)
◀ - 커서를 왼쪽으로 이동 (첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)
▶ - 커서를 오른쪽으로 이동
예를 들어 아래의 방법으로 "JAZ"를 만들 수 있습니다.

- 첫 번째 위치에서 조이스틱을 위로 9번 조작하여 J를 완성합니다.
- 조이스틱을 왼쪽으로 1번 조작하여 커서를 마지막 문자 위치로 이동시킵니다.
- 마지막 위치에서 조이스틱을 아래로 1번 조작하여 Z를 완성합니다.
따라서 11번 이동시켜 "JAZ"를 만들 수 있고, 이때가 최소 이동입니다.
만들고자 하는 이름 name이 매개변수로 주어질 때, 이름에 대해 조이스틱 조작 횟수의 최솟값을 return 하도록 solution 함수를 만드세요.

제한 사항
name은 알파벳 대문자로만 이루어져 있습니다.
name의 길이는 1 이상 20 이하입니다.
입출력 예
name	    return
"JEROEN"	56
"JAN"	    23
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

// pair<최종거리, 루트>
typedef pair<int, vector<int>> pair_int;

void dfs(int _start_index, vector<int> _node_indexs, priority_queue<pair_int, vector<pair_int>, greater<pair_int>>& _pq)
{
    int curr_index = _node_indexs.front();

    for(int i = 0; i < _node_indexs.size(); i++)
    {

    }
}

int solution(string name) {
    int answer = 0;

    // 1. 순서대로 조작이 필요한지 체크
    // 2. 조작이 필요하다면, 원하는 문자까지 최단거리 확인
    // 3. 조작이 필요한 문자까지의 이동 거리 계산

    vector<int> node_indexs;
    priority_queue<pair_int, vector<pair_int>, greater<pair_int>> pq;

    // 탐색해야하는 node index 확인
    // 시작점 삽입
    node_indexs.push_back(0);

    for (int i = 1; i < name.length(); ++i)
    {
        if (name.at(i) != 'A')
        {
            node_indexs.push_back(i);
        }
    }

    int curr = 0;

    for (int i = 0; i < name.length(); ++i)
    {
        // 1. 조작이 필요한지 체크
        if (name.at(i) != 'A')
        {
            // 2. 조작이 필요하다면, 조작하려는 위치까지 최단거리 확인
            answer += (i - curr) < (curr + 1) ? i - curr : curr + 1;

            // 3. 조작하려는 위치에 도달하면, 원하는 문자까지의 최단거리 계산
            answer += (name.at(i) - 'A') < ('Z' + 1 - name.at(i)) ? (name.at(i) - 'A') : ('Z' + 1 - name.at(i));

            curr = i;
        }
    }

    return answer;
}