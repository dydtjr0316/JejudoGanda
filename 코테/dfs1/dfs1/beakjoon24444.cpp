#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 100001

vector<int> node[MAX];
bool isVisited[MAX];
int result[MAX];

queue<int> q;
int n, m, r;
int a, b;
int cnt = 0;
// 너비우선
void bfs(int idx)
{
	q.push(idx);
	isVisited[idx] = true;
	while (!q.empty())
	{
		int t = q.front();
		cnt++;
		result[cnt] = t;

		q.pop();
		for (int i = 0; i < node[t].size(); i++)
		{
			int cur = node[t][i];
			if (!isVisited[cur])
			{
				q.push(cur);
				isVisited[cur] = true;
			}
		}
	}

}
int main()
{
	cin >> n>>m>> r;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		node[a].emplace_back(b);
		node[b].emplace_back(a);
	}
	for (auto& n:node)
	{
		sort(n.begin(), n.end());
	}
	bfs(r);

	for (int i = 1;i<=n;i++)
	{
		cout << result[i] << endl;
	}
}