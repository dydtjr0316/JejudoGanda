#include<iostream>
#include<vector>
#include<string>
#include<queue>

#define MAX 51

using namespace std;

int testCount, w, h, n, result = 0;
int map[MAX][MAX];
int isVisited[MAX][MAX] = { false, };
queue<pair<int, int>> q;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

//유기농 배추
void bfs(int x, int y)
{
	q.push({ x,y });
	isVisited[x][y] = true;
	
	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if ((0 <= nx && nx < w) && (0 <= ny && ny < h))
			{
				if (map[nx][ny] == 1 && isVisited[nx][ny] == false)
				{
					q.push({ nx,ny });
					isVisited[nx][ny] = true;
				}
			}
		}
	}
}
int main()
{
	cin >> testCount;
	for (int i = 0; i < testCount; i++)
	{
		result = 0;
		cin >> w >> h >> n;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			map[a][b] = 1;
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1 && isVisited[i][j] == false)
				{
					bfs(i, j);
					result++;
				}
			}
		}
		cout << endl;
		cout << "결과값" << endl;
		cout << result << endl << endl;
	}
}

