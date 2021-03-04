// �������� ���� ����
/*
���� ����
������ ������ �������� �����濡 �����Ͽ����ϴ�.�� �� ���� ������ �����ϰ�� ��� ������ �������� �����Ͽ����ϴ�.

�����濡 ������ �������� �̸��� ��� �迭 participant�� ������ �������� �̸��� ��� �迭 completion�� �־��� ��, �������� ���� ������ �̸��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
������ ��⿡ ������ ������ ���� 1�� �̻� 100, 000�� �����Դϴ�.
completion�� ���̴� participant�� ���̺��� 1 �۽��ϴ�.
�������� �̸��� 1�� �̻� 20�� ������ ���ĺ� �ҹ��ڷ� �̷���� �ֽ��ϴ�.
������ �߿��� ���������� ���� �� �ֽ��ϴ�.
����� ��
participant	completion	return
[leo, kiki, eden][eden, kiki]	leo
[marina, josipa, nikola, vinko, filipa][josipa, filipa, marina, nikola]	vinko
[mislav, stanko, mislav, ana][stanko, ana, mislav]	mislav
����� �� ����
���� #1
leo�� ������ ��ܿ��� ������, ������ ��ܿ��� ���� ������ �������� ���߽��ϴ�.

���� #2
vinko�� ������ ��ܿ��� ������, ������ ��ܿ��� ���� ������ �������� ���߽��ϴ�.

���� #3
mislav�� ������ ��ܿ��� �� ���� ������, ������ ��ܿ��� �� ��ۿ� ���� ������ �Ѹ��� �������� ���߽��ϴ�.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    bool bFind = false;

    // �� �迭�� ���ϱ� ���ϵ��� ����
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    // �� ����
    for (int i = 0; i < completion.size(); ++i)
    {
        // ���ڿ� �ؽ��� ���� ���� �ӵ��� ��
        if (hash<string>()(participant[i]) != hash<string>()(completion[i]))
        {
            answer = participant[i];
            bFind = true;

            // ������� ���� ����� ã���� for �� Ż��
            break;
        }
    }

    // ������ �����ŭ ���Ͽ����� ������ڸ� ã�� ���Ѱ��
    // ������ �迭�� �������
    if (bFind == false)
    {
        answer = participant[participant.size() - 1];
    }

    return answer;
}
