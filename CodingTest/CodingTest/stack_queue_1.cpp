/*
�ٸ��� ������ Ʈ��

���� ����
Ʈ�� ���� �밡 ���� ���������� �� ���� �ٸ��� ������ ������ �ǳʷ� �մϴ�. ��� Ʈ���� �ٸ��� �ǳʷ��� �ּ� �� �ʰ� �ɸ����� �˾Ƴ��� �մϴ�. Ʈ���� 1�ʿ� 1��ŭ �����̸�, �ٸ� ���̴� bridge_length�̰� �ٸ��� ���� weight���� �ߵ��ϴ�.
�� Ʈ���� �ٸ��� ������ ������ ���� ���, �� Ʈ���� ���Դ� ������� �ʽ��ϴ�.

���� ���, ���̰� 2�̰� 10kg ���Ը� �ߵ�� �ٸ��� �ֽ��ϴ�. ���԰� [7, 4, 5, 6]kg�� Ʈ���� ������� �ִ� �ð� �ȿ� �ٸ��� �ǳʷ��� ������ ���� �ǳʾ� �մϴ�.

��� �ð�	�ٸ��� ���� Ʈ��	�ٸ��� �ǳʴ� Ʈ��	��� Ʈ��
0	[]	[]	[7,4,5,6]
1~2	[]	[7]	[4,5,6]
3	[7]	[4]	[5,6]
4	[7]	[4,5]	[6]
5	[7,4]	[5]	[6]
6~7	[7,4,5]	[6]	[]
8	[7,4,5,6]	[]	[]
����, ��� Ʈ���� �ٸ��� �������� �ּ� 8�ʰ� �ɸ��ϴ�.

solution �Լ��� �Ű������� �ٸ� ���� bridge_length, �ٸ��� �ߵ� �� �ִ� ���� weight, Ʈ���� ���� truck_weights�� �־����ϴ�. �̶� ��� Ʈ���� �ٸ��� �ǳʷ��� �ּ� �� �ʰ� �ɸ����� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���� ����
bridge_length�� 1 �̻� 10,000 �����Դϴ�.
weight�� 1 �̻� 10,000 �����Դϴ�.
truck_weights�� ���̴� 1 �̻� 10,000 �����Դϴ�.
��� Ʈ���� ���Դ� 1 �̻� weight �����Դϴ�.
����� ��
bridge_length	weight	truck_weights	return
2	10	[7,4,5,6]	8
100	100	[10]	101
100	100	[10,10,10,10,10,10,10,10,10,10]	110
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int time = 0;

	queue<int> on_bridge_truck_que;
	int start_truck_cnt = 0;
	int end_truck_cnt = 0;
	int on_bridge_weights = 0;

	while (end_truck_cnt != truck_weights.size())
	{
		// �ð� ����
		++time;

		// ���� �ð� - Ʈ���� �ٸ��� �ö�� �ð� == �ٸ� ����
		// ���� 6�� - �ö�� �ð� 1�� == 5�� == �ٸ����� -> Ʈ�� pop
		if (on_bridge_truck_que.size() > 0 && time - on_bridge_truck_que.front() == bridge_length)
		{
			on_bridge_weights -= truck_weights[end_truck_cnt];
			on_bridge_truck_que.pop();

			++end_truck_cnt;
		}

		// Ʈ���� �ٸ��� �ö�� �� �ִ��� Ȯ�� ��
		// Ʈ���� �ö�� �ð��� ť�� ����
		if (start_truck_cnt < truck_weights.size() && on_bridge_weights + truck_weights[start_truck_cnt] <= weight)
		{
			on_bridge_truck_que.push(time);

			on_bridge_weights += truck_weights[start_truck_cnt];
			++start_truck_cnt;
		}
	}

	return time;
}

//void main()
//{
//	int result = solution(2, 10, { 7, 4, 5, 6 });
//
//	cout << result << endl;
//}