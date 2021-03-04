/*
문제 설명
스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다.노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.

속한 노래가 많이 재생된 장르를 먼저 수록합니다.
장르 내에서 많이 재생된 노래를 먼저 수록합니다.
장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
노래의 장르를 나타내는 문자열 배열 genres와 노래별 재생 횟수를 나타내는 정수 배열 plays가 주어질 때, 베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return 하도록 solution 함수를 완성하세요.

제한사항
genres[i]는 고유번호가 i인 노래의 장르입니다.
plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.
genres와 plays의 길이는 같으며, 이는 1 이상 10, 000 이하입니다.
장르 종류는 100개 미만입니다.
장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
모든 장르는 재생된 횟수가 다릅니다.

입출력 예

genres	                                        plays	                    return
["classic", "pop", "classic", "classic", "pop"] [500, 600, 150, 800, 2500]  [4, 1, 3, 0]

입출력 예 설명

classic 장르는 1, 450회 재생되었으며, classic 노래는 다음과 같습니다.

고유 번호 3: 800회 재생
고유 번호 0 : 500회 재생
고유 번호 2 : 150회 재생
pop 장르는 3, 100회 재생되었으며, pop 노래는 다음과 같습니다.

고유 번호 4 : 2, 500회 재생
고유 번호 1 : 600회 재생
따라서 pop 장르의[4, 1]번 노래를 먼저, classic 장르의[3, 0]번 노래를 그다음에 수록합니다.
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef pair<int, int> pair_int;
typedef pair<string, int> string_int;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    // 장르별 곡 번호와 재생 횟수를 담을 컨테이너
    unordered_map<string, vector<pair_int>> total;

    // 장르별 총 재생 횟수를 담을 컨테이너
    unordered_map<string, int> total_cnt;    

    // 컨테이너 삽입
    for (int i = 0; i < plays.size(); ++i)
    {
        total[genres[i]].push_back(pair_int(plays[i], i));

        if (total_cnt.find(genres[i]) == total_cnt.end())
            total_cnt[genres[i]] = plays[i];
        else
            total_cnt[genres[i]] += plays[i];
    }
    
    // 장르별 총 재생 횟수를 내림차순으로 정렬
    vector<string_int> total_cnt_vector(total_cnt.begin(), total_cnt.end());
    
    sort(total_cnt_vector.begin(), total_cnt_vector.end(), [](string_int _left, string_int _right) {
        return _left.second > _right.second;
    });

    // 장르별 곡들의 재생 순위 내림차순 정렬
    for (int i = 0; i < plays.size(); ++i)
    {
        sort(total[genres[i]].begin(), total[genres[i]].end(), [](pair_int _left, pair_int _right) {
            return _left.first > _right.first;
        });
    }

    // 장르 순위별 top 2 추출
    for (auto& elem : total_cnt_vector)
    {
        for (int i = 0; i < total[elem.first].size(); ++i)
        {
            answer.push_back(total[elem.first][i].second);

            if (i >= 1)
                break;
        }
    }

    return answer;
}