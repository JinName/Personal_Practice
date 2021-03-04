/*
���� ����
�����̵��� ���� �ٸ� ���� �����Ͽ� �Ծ� �ڽ��� �����մϴ�.

���� ��� �����̰� ���� ���� �Ʒ��� ���� ���� �����̰� ���׶� �Ȱ�, �� ��Ʈ, �Ķ��� Ƽ������ �Ծ��ٸ� �������� û������ �߰��� �԰ų� ���׶� �Ȱ� ��� ���� ���۶󽺸� �����ϰų� �ؾ� �մϴ�.

����	�̸�
��	���׶� �Ȱ�, ���� ���۶�
����	�Ķ��� Ƽ����
����	û����
�ѿ�	�� ��Ʈ
�����̰� ���� �ǻ���� ��� 2���� �迭 clothes�� �־��� �� ���� �ٸ� ���� ������ ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
clothes�� �� ����[�ǻ��� �̸�, �ǻ��� ����]�� �̷���� �ֽ��ϴ�.
�����̰� ���� �ǻ��� ���� 1�� �̻� 30�� �����Դϴ�.
���� �̸��� ���� �ǻ��� �������� �ʽ��ϴ�.
clothes�� ��� ���Ҵ� ���ڿ��� �̷���� �ֽ��ϴ�.
��� ���ڿ��� ���̴� 1 �̻� 20 ������ �ڿ����̰� ���ĺ� �ҹ��� �Ǵ� '_' �θ� �̷���� �ֽ��ϴ�.
�����̴� �Ϸ翡 �ּ� �� ���� �ǻ��� �Խ��ϴ�.

����� ��

clothes	return
[["yellowhat", "headgear"], ["bluesunglasses", "eyewear"], ["green_turban", "headgear"]] 5
[["crowmask", "face"], ["bluesunglasses", "face"], ["smoky_makeup", "face"]] 3


����� �� ����

���� #1
headgear�� �ش��ϴ� �ǻ��� yellow_hat, green_turban�̰� eyewear�� �ش��ϴ� �ǻ��� blue_sunglasses�̹Ƿ� �Ʒ��� ���� 5���� ������ �����մϴ�.

1. yellow_hat
2. blue_sunglasses
3. green_turban
4. yellow_hat + blue_sunglasses
5. green_turban + blue_sunglasses

���� #2
face�� �ش��ϴ� �ǻ��� crow_mask, blue_sunglasses, smoky_makeup�̹Ƿ� �Ʒ��� ���� 3���� ������ �����մϴ�.

1. crow_mask
2. blue_sunglasses
3. smoky_makeup
*/


#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// ���� ���� ���� ���Դ� �͵� ��쿡 ���Խ�Ű��
// ��� �� ������ ������ ���ϸ� ���� ���� ������
// �ű⼭ ���� ���Դ� ��츦 -1 ���ش�.

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> kinds;

    // �� ������ ���� Ȯ��
    for (auto& i : clothes)
    {
        if (kinds.find(i[1]) == kinds.end())
            kinds[i[1]] = 1;
        else
            kinds[i[1]] += 1;
    }

    unordered_map<string, int>::iterator iter = kinds.begin();

    // ���
    while (iter != kinds.end())
    {
        answer = answer * (iter->second + 1);
        ++iter;
    }

    return answer - 1;
}

//int main()
//{
//    vector<vector<string>> clothes;
//    clothes.push_back({ "yellowhat", "headgear" });
//    clothes.push_back({ "bluesunglasses", "eyewear" });
//    clothes.push_back({ "green_turban", "headgear" });
//
//    int result = solution(clothes);
//
//    cout << result << endl;
//
//    return 0;
//}