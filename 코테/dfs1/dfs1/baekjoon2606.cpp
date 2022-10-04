#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> node[1000];
bool isVisited[1000] = { false, };
int n, line;
int cnt = 0;

void dfs(int idx)
{
	if (isVisited[idx])return;

	isVisited[idx] = true;
	cnt++;
	
	for (auto i = 0; i < node[idx].size(); ++i)
	{
		dfs(node[idx][i]);
	}
}

int main(void)
{
	//scanf_s("%d%d", &n, &line);
	cin >> n >> line;
	for (int i = 1; i <= line; i++)
	{
		int a, b;
		//scanf_s("%d%d", &a, &b);
		cin >> a >> b;
		node[a].emplace_back(b);
		node[b].emplace_back(a);
	}
	for (int i = 1; i <= line; i++)
	{
		sort(node[i].begin(), node[i].end());
	}

	dfs(1);

	cout << cnt-1 << endl;
}