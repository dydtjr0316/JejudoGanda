#include<iostream>
#include<queue>
#include<deque>
#include<string.h>
#include<math.h>
#include<cmath>
#include<stack>
#include<algorithm>

using namespace std;

vector<int> graph[100001];
bool visited[100001] = { false, };
int result[100001];
int cnt = 0;
void dfs(int idx)
{
	if (visited[idx])return;

	visited[idx] = true;
	++cnt;
	result[idx] = cnt;

	for (int i = 0; i < graph[idx].size(); i++) {
		dfs(graph[idx][i]);
	}
}
int main()
{
	int n, m, r;
	int a, b;
	cin >> n >> m >> r;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}
	for (int i = 0; i < n; ++i)
	{
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(r);
	for (int i = 1; i <= n; i++) {
		printf("%d\n", result[i]);
	}

	return ;
}

