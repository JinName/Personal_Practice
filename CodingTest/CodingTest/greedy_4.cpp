/*
구명보트
문제 설명
무인도에 갇힌 사람들을 구명보트를 이용하여 구출하려고 합니다. 구명보트는 작아서 한 번에 최대 2명씩 밖에 탈 수 없고, 무게 제한도 있습니다.

예를 들어, 사람들의 몸무게가 [70kg, 50kg, 80kg, 50kg]이고 구명보트의 무게 제한이 100kg이라면 2번째 사람과 4번째 사람은 같이 탈 수 있지만 1번째 사람과 3번째 사람의 무게의 합은 150kg이므로 구명보트의 무게 제한을 초과하여 같이 탈 수 없습니다.

구명보트를 최대한 적게 사용하여 모든 사람을 구출하려고 합니다.

사람들의 몸무게를 담은 배열 people과 구명보트의 무게 제한 limit가 매개변수로 주어질 때, 모든 사람을 구출하기 위해 필요한 구명보트 개수의 최솟값을 return 하도록 solution 함수를 작성해주세요.

제한사항
무인도에 갇힌 사람은 1명 이상 50,000명 이하입니다.
각 사람의 몸무게는 40kg 이상 240kg 이하입니다.
구명보트의 무게 제한은 40kg 이상 240kg 이하입니다.
구명보트의 무게 제한은 항상 사람들의 몸무게 중 최댓값보다 크게 주어지므로 사람들을 구출할 수 없는 경우는 없습니다.
입출력 예
people	            limit	    return
[70, 50, 80, 50]	100	        3
[70, 80, 50]	    100	        3
*/


//#include <string>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//int solution(vector<int> people, int limit) {
//    int answer = 0;   
//
//    // 1 try
//    // 1. 보트를 타는 횟수 별로 공간을 구성하는 자료구조를 만든다.
//    // 2. for 문을 돌면서 공간에 여유가 있는지 검사하고, 있으면 넣고 없으면 새로운 공간을 배정한다.
//    
//    /*
//    vector<int> boat_arr;
//    bool on_boat = false;
//
//    for (auto& elem : people)
//    {
//        on_boat = false;
//
//        for (auto& boat : boat_arr)
//        {
//            if (limit - boat >= elem)
//            {
//                boat += elem;
//                on_boat = true;
//                break;
//            }
//        }
//
//        if (!on_boat)
//        {
//            boat_arr.push_back(elem);
//        }
//    }
//
//    answer = boat_arr.size();
//    */
//
//    // 2 try
//    // 우선순위 큐로 제일 무게가 낮은 사람부터 뽑아서 태워 보낸다.
//
//    /*
//    priority_queue<int, vector<int>, greater<int>> pq;
//
//    // 현재 보트 올라탄 총 무게
//    int on_boat_weight = 0;
//
//    // 1. 우선순위 큐에 데이터 전부 삽입
//    for (auto& elem : people)
//    {
//        pq.push(elem);
//    }
//
//    // 2. 우선순위 큐 맨 위에서 보트에 하나씩 태우고
//    // 더이상 태울 수 없을 경우 기존 보트를 보내고 ++cnt
//    while (!pq.empty())
//    {
//        // 보트에 넣을 수 있는지 검사
//        if (limit - on_boat_weight >= pq.top())
//        {
//            on_boat_weight += pq.top();
//            pq.pop();
//        }
//        // 보트에 넣을 수 없으면 보트를 보내고 횟수 + 1
//        else
//        {
//            // 보트 사용 횟수 + 1
//            ++answer;
//
//            // 보트 무게 초기화 후 다시 삽입
//            on_boat_weight = 0;
//            on_boat_weight = pq.top();
//            pq.pop();
//        }
//    }
//
//    // 우선순위 큐를 다 확인한 경우
//    // 마지막 남은 보트를 보내고 횟수 + 1
//    if (on_boat_weight > 0)
//    {
//        ++answer;
//    }
//    */
//
//    // 3 try
//    // 우선순위 큐 2개 (최대힙, 최소힙)
//
//    /*
//    priority_queue<int> max_pq;
//    priority_queue<int, vector<int>, greater<int>> min_pq;
//    int pq_cnt = 0;
//
//    int on_boat_weight = 0;
//
//    bool max_pq_switch = true;
//    bool min_pq_switch = true;
//
//    // 1. 우선순위 큐에 모두 삽입
//    for (auto& elem : people)
//    {
//        max_pq.push(elem);
//        min_pq.push(elem);
//
//        ++pq_cnt;
//    }
//
//    // 2. 최대힙과 최소힙 top 을 더했을 때 on_boat_weight 가
//    // if (limit >= on_boat_weight) 최대힙은 그대로, 최소힙에서 하나 더 꺼내어 삽입 가능한지 확인
//    // if (limit < on_boat_weight) 최소힙은 그대로, 현재 최대힙을 pop 하고 새로운 최대힙을 꺼내서 삽입 가능한지 확인
//    while (pq_cnt != 0)
//    {
//        int min_top = 0;
//        int max_top = 0;       
//
//        // 최소힙에서 꺼내야하는 경우
//        if (min_pq_switch)
//        {
//            min_top = min_pq.top();
//            min_pq.pop();
//            --pq_cnt;
//
//            on_boat_weight += min_top;
//            min_pq_switch = false;
//        }
//
//        // 최대힙에서 꺼내야하는 경우
//        if (max_pq_switch && pq_cnt != 0)
//        {
//            max_top = max_pq.top();
//            max_pq.pop();
//            --pq_cnt;
//
//            on_boat_weight += max_top;
//            max_pq_switch = false;
//        }
//
//        
//        // 최대힙 최소힙 합쳐서 한계치보다 많은 경우 -> 최대힙 하나를 pop 하고, 최대힙을 하나 더 꺼내옴
//        if (on_boat_weight > limit)
//        {
//            on_boat_weight -= max_top;
//
//            max_pq_switch = true;
//
//            ++answer;
//        }
//        // 딱 맞는 경우 보트 비우고 새로운 최대힙 최소힙을 받는다.
//        else
//        {    
//            on_boat_weight = 0;
//            ++answer;
//
//            min_pq_switch = true;
//            max_pq_switch = true;
//        }
//    }
//
//    // 마지막 보트 보내기
//    if (on_boat_weight > 0)
//    {
//        ++answer;
//    }
//    */
//
//    // 4 try
//    // sort 함수를 통해 양쪽 끝에서부터 하나씩 보트에 태우기
//
//    int arr_size = people.size();
//    int front = 0;
//    int rear = arr_size - 1;
//
//    int on_boat_weight = 0;
//
//    sort(people.begin(), people.end());
//
//    while (arr_size > 0)
//    {
//        // 보트에 태우기
//        // 제일 무거운 사람부터 태우고, 제일 가벼운 사람을 태웠을때 무게가 초과된다면 보트를 보낸다.
//        on_boat_weight += people[rear];
//
//        if (front != rear)
//            on_boat_weight += people[front];
//
//        if (on_boat_weight > limit)
//        {
//            ++answer;
//
//            on_boat_weight = 0;
//
//            --rear;
//            --arr_size;
//        }
//        // 보트 무게가 limit 보다 작거나 같으면, 2명이 탄 상태니 출발한다.
//        else
//        {
//            ++answer;
//
//            on_boat_weight = 0;
//
//            ++front;
//            --rear;
//            arr_size -= 2;
//        }
//    }
//
//    return answer;
//}


//int main()
//{
//    cout << solution({ 70, 80, 50 }, 100) << endl;
//
//    return 0;
//}