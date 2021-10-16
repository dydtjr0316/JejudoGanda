#include<iostream>
#include <vector>

using namespace std;
vector<int> solution(int n, vector<vector<int>> quests);
void DFS(int n, vector<vector<int>> quests);
//12354
//13 14 35 54
int main()
{

    vector<vector<int>> a;
    a.resize(4);

    a[0].push_back(1);
    a[0].push_back(3);

    a[1].push_back(1);
    a[1].push_back(4);

    a[2].push_back(3);
    a[2].push_back(5);

    a[3].push_back(5);
    a[3].push_back(4);

    vector<int> temp = solution(5, a);

    for (int i = 0; i < temp.size(); ++i)
        cout << temp[i] << endl;
    return 0;
}
vector<int> solution(int n, vector<vector<int>> quests)
{
    vector<int> answer;
    vector<int> node;
    for (int i = 1; i <= n; ++i)
        node.push_back(i);


    while (!node.empty())
    {
        for (int i = 0; i < node.size(); ++i)
        {
            bool check = false;
            int Num = node[i];
            vector<int> DeleteNode;
            for (int j = 0; j < quests.size(); ++j)
            {
                if (Num == quests[j][1])
                {
                    check = true;
                    break;
                }
                if (Num == quests[j][0])
                    DeleteNode.push_back(j);
            }
            if (check == false)
            {
                answer.push_back(Num);
                node.erase(node.begin() + i);
                for (int i = 0; i < DeleteNode.size(); ++i)
                    quests.erase(quests.begin() + (DeleteNode[i] - i));

                break;
            }

        }
    }
    return answer;
}

