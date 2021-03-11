/*
디스크 컨트롤러

문제 설명
하드디스크는 한 번에 하나의 작업만 수행할 수 있습니다. 디스크 컨트롤러를 구현하는 방법은 여러 가지가 있습니다. 가장 일반적인 방법은 요청이 들어온 순서대로 처리하는 것입니다.

예를들어

- 0ms 시점에 3ms가 소요되는 A작업 요청
- 1ms 시점에 9ms가 소요되는 B작업 요청
- 2ms 시점에 6ms가 소요되는 C작업 요청
와 같은 요청이 들어왔습니다. 이를 그림으로 표현하면 아래와 같습니다.
Screen Shot 2018-09-13 at 6.34.58 PM.png

한 번에 하나의 요청만을 수행할 수 있기 때문에 각각의 작업을 요청받은 순서대로 처리하면 다음과 같이 처리 됩니다.
Screen Shot 2018-09-13 at 6.38.52 PM.png

- A: 3ms 시점에 작업 완료 (요청에서 종료까지 : 3ms)
- B: 1ms부터 대기하다가, 3ms 시점에 작업을 시작해서 12ms 시점에 작업 완료(요청에서 종료까지 : 11ms)
- C: 2ms부터 대기하다가, 12ms 시점에 작업을 시작해서 18ms 시점에 작업 완료(요청에서 종료까지 : 16ms)
이 때 각 작업의 요청부터 종료까지 걸린 시간의 평균은 10ms(= (3 + 11 + 16) / 3)가 됩니다.

하지만 A → C → B 순서대로 처리하면
Screen Shot 2018-09-13 at 6.41.42 PM.png

- A: 3ms 시점에 작업 완료(요청에서 종료까지 : 3ms)
- C: 2ms부터 대기하다가, 3ms 시점에 작업을 시작해서 9ms 시점에 작업 완료(요청에서 종료까지 : 7ms)
- B: 1ms부터 대기하다가, 9ms 시점에 작업을 시작해서 18ms 시점에 작업 완료(요청에서 종료까지 : 17ms)
이렇게 A → C → B의 순서로 처리하면 각 작업의 요청부터 종료까지 걸린 시간의 평균은 9ms(= (3 + 7 + 17) / 3)가 됩니다.

각 작업에 대해 [작업이 요청되는 시점, 작업의 소요시간]을 담은 2차원 배열 jobs가 매개변수로 주어질 때, 작업의 요청부터 종료까지 걸린 시간의 평균을 가장 줄이는 방법으로 처리하면 평균이 얼마가 되는지 return 하도록 solution 함수를 작성해주세요. (단, 소수점 이하의 수는 버립니다)

제한 사항
jobs의 길이는 1 이상 500 이하입니다.
jobs의 각 행은 하나의 작업에 대한 [작업이 요청되는 시점, 작업의 소요시간] 입니다.
각 작업에 대해 작업이 요청되는 시간은 0 이상 1,000 이하입니다.
각 작업에 대해 작업의 소요시간은 1 이상 1,000 이하입니다.
하드디스크가 작업을 수행하고 있지 않을 때에는 먼저 요청이 들어온 작업부터 처리합니다.
입출력 예
jobs	return
[[0, 3], [1, 9], [2, 6]]	9
입출력 예 설명
문제에 주어진 예와 같습니다.

0ms 시점에 3ms 걸리는 작업 요청이 들어옵니다.
1ms 시점에 9ms 걸리는 작업 요청이 들어옵니다.
2ms 시점에 6ms 걸리는 작업 요청이 들어옵니다.
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

// 무조건 처리시간이 짧은 것부터 처리해야 평균 처리시간이 줄어든다.
// 시점이 빠른 것부터 처리를 시작하고,
// 해당 작업의 처리시간 내에 요청이 들어오는 작업들에 대해 처리시간이 짧은 것부터 처리한다.
// 현재 진행 중인 작업 시간 내에 겹치는 요청 중에 먼저 처리할 작업을 따로 저장해야 함.

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    int time = 0;
    int time_stack = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> low_pair_pq;
    queue<pair<int, int>> temp_que;
    pair<int, int> next_task;

    // 우선순위 큐에 정렬
    for (auto& elem : jobs)
    {
        low_pair_pq.push({ elem[0], elem[1] });
    }

    next_task = low_pair_pq.top();
    low_pair_pq.pop();
    time += next_task.first;

    while (!low_pair_pq.empty())
    {
        // 현재 작업 완료 시간
        time += next_task.second;
        time_stack += time - next_task.first;

        if (!low_pair_pq.empty())
        {
            next_task = low_pair_pq.top();
            low_pair_pq.pop();

            // 처리 시간 내에 요청 작업 중 더 짧은 처리 시간을 next_task 로 지정한다.
            // next_task 에서 탈락한 것들은 temp_que 에 모아놓았다가 우선순위 큐로 다시 삽입.

            while (!low_pair_pq.empty() && low_pair_pq.top().first < time)
            {
                pair<int, int> temp_task = low_pair_pq.top();
                low_pair_pq.pop();

                if (temp_task.second > next_task.second)
                {
                    temp_que.push(temp_task);
                }
                else
                {
                    temp_que.push(next_task);
                    next_task = temp_task;
                }
            }

            // 비교가 끝나면 임시 큐 -> 우선순위 큐 다시 삽입
            int size = temp_que.size();
            for (int i = 0; i < size; ++i)
            {
                pair<int, int> temp_task = temp_que.front();
                temp_que.pop();

                low_pair_pq.push(temp_task);
            }
        }
    }

    // 마지막 작업 처리 시간 계산
    time += next_task.second;
    time_stack += time - next_task.first;

    // 요청 처리 시간 평균값 계산
    answer = time_stack / jobs.size();

    return answer;
}