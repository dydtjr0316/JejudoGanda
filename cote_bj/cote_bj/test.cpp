#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int score[3] = { 0, };
    int P1[5] = { 1,2,3,4,5 };
    int P2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    int P3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    for (int i = 0; i < answers.size()+1; ++i)
    {
        if (answers[i] == P1[(i % 5)])score[0]++;
        if (answers[i] == P2[(i % 8)])score[1]++;
        if (answers[i] == P3[(i % 10)])score[2]++;
    }
    int max_score = max(max(score[0], score[1]), score[2]);
    for (int i = 0; i < 3; i++)
    {
        if (max_score == score[i])answer.emplace_back(i+1);
    }
    return answer;
}