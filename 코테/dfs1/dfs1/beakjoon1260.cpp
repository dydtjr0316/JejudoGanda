#include<iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

vector<int> node[1001];
bool isVisieted[1001] = { false, };
vector<int> result;
queue<int> q;
int n, m, v;

// dfs bfs 순회 순서 구하기

void dfs(int idx)
{
	if (isVisieted[idx])return;
	isVisieted[idx] = true;

	result.emplace_back(idx);

	for (int i = 0;i<node[idx].size();i++)
	{
		dfs(node[idx][i]);
	}

}
void bfs(int idx)
{
	q.push(idx);
	isVisieted[idx] = true;

	while (!q.empty())
	{
		int t = q.front();
		result.emplace_back(t);
		q.pop();
		for (int i = 0; i < node[t].size();++i)
		{
			int cur = node[t][i];
			if (!isVisieted[cur])
			{
				q.push(cur);
				isVisieted[cur] = true;
			}
		}
	}
}
int main()
{
	cin >> n >> m >> v;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		node[a].emplace_back(b);
		node[b].emplace_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(node[i].begin(), node[i].end());
	}
	dfs(v);
	for (auto& obj : result)
	{
		cout << obj << " ";
	}
	cout << endl;

	node->clear();
	result.clear();

	for (int i = 1; i <= n; i++)
	{
		isVisieted[i] = false;
	}

	bfs(v);
	for (auto& obj : result)
	{
		cout << obj << " ";
	}
}