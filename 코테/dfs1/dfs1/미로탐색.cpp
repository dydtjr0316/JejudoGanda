#include<iostream>
#include<vector>
#include<queue>
#include<string>
#define MAX 101

using namespace std;

int n, m;
vector<int> result;
string map[MAX];
queue<pair<int, int>> q;
bool isVisited[MAX][MAX] = { false, };
int dist[MAX][MAX] = { 0, };

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
// 미로 최단 거리

void bfs(int x, int y)
{
	q.push({ x, y});
	isVisited[x][y] = true;
	dist[x][y] = 1;
	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nX = curX + dx[i];
			int nY = curY + dy[i];
			if ((0 <= nX && nX < n) && (0 <= nY && nY < m))
			{
				if (map[nX][nY] == '1' && isVisited[nX][nY] == false)
				{
					isVisited[nX][nY] = true;
					q.push({ nX, nY });
					dist[nX][nY] = dist[curX][curY] + 1;
				}
			}
		}

	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}
	bfs(0,0);
	cout << dist[n - 1][m - 1];
}