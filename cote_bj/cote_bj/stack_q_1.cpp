#include <string>
#include <vector>
#include <stack>

using namespace std;

//vector<int> solution(vector<int> progresses, vector<int> speeds) {
//    vector<int> answer;
//    int cnt = 0;
//    while (true)
//    {
//        if (progresses.size() == 0)break;
//        for (int i = 0; i < progresses.size(); ++i)
//        {
//            progresses[i] += speeds[i];
//            if (progresses[i] += speeds[i] >= 100)
//            {
//                progresses.erase(progresses.begin());
//                speeds.erase(speeds.begin());
//                cnt++;
//            }
//            else
//                break;
//        }
//        answer.emplace_back(cnt);
//        cnt = 0;
//    }
// 
//    return answer;
//}
//vector<int> solution(vector<int> progresses, vector<int> speeds) {
//    vector<int> answer;
//    stack<int> work;
//    int cnt = 0;
//    while (progresses.size() != 0)
//    {
//        for (int i = 0; i < progresses.size(); ++i)
//        {
//            progresses[i] += speeds[i]; // 하루 하루 +
//            if (progresses[i] + speeds[i] >= 100)
//            {
//                progresses.erase(progresses.begin());
//                speeds.erase(speeds.begin());
//                cnt++;
//            }
//            else
//            {
//                if (cnt > 0)
//                {
//                    answer.emplace_back(cnt);
//                    cnt = 0;
//                }
//                else
//                {
//                    for (int j = i+1; j < progresses.size(); j++)
//                    {
//                        progresses[j] += speeds[j];
//                    }
//                }
//                break;
//            }
//        }
//
//    }
//
//    return answer;
//}
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int day;
    int max_day = 0;
    for (int i = 0; i < progresses.size(); ++i)
    {
        day = (99 - progresses[i]) / speeds[i] + 1;

        if (answer.empty() || max_day < day)
            answer.push_back(1);
        else
            ++answer.back();

        if (max_day < day)
            max_day = day;
    }

    return answer;
}
int main()
{
    vector<int> pro{ 93,30,55 };
    vector<int> speed{ 1,30,5 };
    solution(pro, speed);
}