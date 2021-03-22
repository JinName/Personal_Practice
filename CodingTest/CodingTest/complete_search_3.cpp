/*
ī��
���� ����
Leo�� ī���� �緯 ���ٰ� �Ʒ� �׸��� ���� �߾ӿ��� ��������� ĥ���� �ְ� �׵θ� 1���� �������� ĥ���� �ִ� ���� ��� ī���� �ý��ϴ�.

carpet.png

Leo�� ������ ���ƿͼ� �Ʊ� �� ī���� ������� �������� ��ĥ�� ������ ������ ���������, ��ü ī���� ũ��� ������� ���߽��ϴ�.

Leo�� �� ī�꿡�� ���� ������ �� brown, ����� ������ �� yellow�� �Ű������� �־��� �� ī���� ����, ���� ũ�⸦ ������� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
���� ������ �� brown�� 8 �̻� 5,000 ������ �ڿ����Դϴ�.
����� ������ �� yellow�� 1 �̻� 2,000,000 ������ �ڿ����Դϴ�.
ī���� ���� ���̴� ���� ���̿� ���ų�, ���� ���̺��� ��ϴ�.
����� ��
brown	yellow	return
10	2	[4, 3]
8	1	[3, 3]
24	24	[8, 6]
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int width = 0;
    int height = 0;

    int area_size = brown + yellow;

    height = 2;

    do
    {
        ++height;

        if (area_size % height == 0)
            width = area_size / height;


    } while ((width - 2) * (height - 2) != yellow);

    answer.push_back(width);
    answer.push_back(height);

    return answer;
}