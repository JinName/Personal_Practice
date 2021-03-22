/*
����Ʈ
���� ����
���ε��� ���� ������� ����Ʈ�� �̿��Ͽ� �����Ϸ��� �մϴ�. ����Ʈ�� �۾Ƽ� �� ���� �ִ� 2�� �ۿ� Ż �� ����, ���� ���ѵ� �ֽ��ϴ�.

���� ���, ������� �����԰� [70kg, 50kg, 80kg, 50kg]�̰� ����Ʈ�� ���� ������ 100kg�̶�� 2��° ����� 4��° ����� ���� Ż �� ������ 1��° ����� 3��° ����� ������ ���� 150kg�̹Ƿ� ����Ʈ�� ���� ������ �ʰ��Ͽ� ���� Ż �� �����ϴ�.

����Ʈ�� �ִ��� ���� ����Ͽ� ��� ����� �����Ϸ��� �մϴ�.

������� �����Ը� ���� �迭 people�� ����Ʈ�� ���� ���� limit�� �Ű������� �־��� ��, ��� ����� �����ϱ� ���� �ʿ��� ����Ʈ ������ �ּڰ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
���ε��� ���� ����� 1�� �̻� 50,000�� �����Դϴ�.
�� ����� �����Դ� 40kg �̻� 240kg �����Դϴ�.
����Ʈ�� ���� ������ 40kg �̻� 240kg �����Դϴ�.
����Ʈ�� ���� ������ �׻� ������� ������ �� �ִ񰪺��� ũ�� �־����Ƿ� ������� ������ �� ���� ���� �����ϴ�.
����� ��
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
//    // 1. ��Ʈ�� Ÿ�� Ƚ�� ���� ������ �����ϴ� �ڷᱸ���� �����.
//    // 2. for ���� ���鼭 ������ ������ �ִ��� �˻��ϰ�, ������ �ְ� ������ ���ο� ������ �����Ѵ�.
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
//    // �켱���� ť�� ���� ���԰� ���� ������� �̾Ƽ� �¿� ������.
//
//    /*
//    priority_queue<int, vector<int>, greater<int>> pq;
//
//    // ���� ��Ʈ �ö�ź �� ����
//    int on_boat_weight = 0;
//
//    // 1. �켱���� ť�� ������ ���� ����
//    for (auto& elem : people)
//    {
//        pq.push(elem);
//    }
//
//    // 2. �켱���� ť �� ������ ��Ʈ�� �ϳ��� �¿��
//    // ���̻� �¿� �� ���� ��� ���� ��Ʈ�� ������ ++cnt
//    while (!pq.empty())
//    {
//        // ��Ʈ�� ���� �� �ִ��� �˻�
//        if (limit - on_boat_weight >= pq.top())
//        {
//            on_boat_weight += pq.top();
//            pq.pop();
//        }
//        // ��Ʈ�� ���� �� ������ ��Ʈ�� ������ Ƚ�� + 1
//        else
//        {
//            // ��Ʈ ��� Ƚ�� + 1
//            ++answer;
//
//            // ��Ʈ ���� �ʱ�ȭ �� �ٽ� ����
//            on_boat_weight = 0;
//            on_boat_weight = pq.top();
//            pq.pop();
//        }
//    }
//
//    // �켱���� ť�� �� Ȯ���� ���
//    // ������ ���� ��Ʈ�� ������ Ƚ�� + 1
//    if (on_boat_weight > 0)
//    {
//        ++answer;
//    }
//    */
//
//    // 3 try
//    // �켱���� ť 2�� (�ִ���, �ּ���)
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
//    // 1. �켱���� ť�� ��� ����
//    for (auto& elem : people)
//    {
//        max_pq.push(elem);
//        min_pq.push(elem);
//
//        ++pq_cnt;
//    }
//
//    // 2. �ִ����� �ּ��� top �� ������ �� on_boat_weight ��
//    // if (limit >= on_boat_weight) �ִ����� �״��, �ּ������� �ϳ� �� ������ ���� �������� Ȯ��
//    // if (limit < on_boat_weight) �ּ����� �״��, ���� �ִ����� pop �ϰ� ���ο� �ִ����� ������ ���� �������� Ȯ��
//    while (pq_cnt != 0)
//    {
//        int min_top = 0;
//        int max_top = 0;       
//
//        // �ּ������� �������ϴ� ���
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
//        // �ִ������� �������ϴ� ���
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
//        // �ִ��� �ּ��� ���ļ� �Ѱ�ġ���� ���� ��� -> �ִ��� �ϳ��� pop �ϰ�, �ִ����� �ϳ� �� ������
//        if (on_boat_weight > limit)
//        {
//            on_boat_weight -= max_top;
//
//            max_pq_switch = true;
//
//            ++answer;
//        }
//        // �� �´� ��� ��Ʈ ���� ���ο� �ִ��� �ּ����� �޴´�.
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
//    // ������ ��Ʈ ������
//    if (on_boat_weight > 0)
//    {
//        ++answer;
//    }
//    */
//
//    // 4 try
//    // sort �Լ��� ���� ���� ���������� �ϳ��� ��Ʈ�� �¿��
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
//        // ��Ʈ�� �¿��
//        // ���� ���ſ� ������� �¿��, ���� ������ ����� �¿����� ���԰� �ʰ��ȴٸ� ��Ʈ�� ������.
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
//        // ��Ʈ ���԰� limit ���� �۰ų� ������, 2���� ź ���´� ����Ѵ�.
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