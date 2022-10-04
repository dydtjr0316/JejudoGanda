#include<iostream>
#include<vector>
#include<queue>
#include <string>
#define MAX 26

using namespace std;

string map[MAX];
bool isVisited[MAX][MAX] = { false, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0, 1, -1 };
vector<int> result;
queue<pair<int, int>> q;
int n, cnt = 0;

void bfs(int x, int y)
{
	q.push({ x,y });
	isVisited[x][y] = true;
	cnt++;

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if ((0 <= nx && nx < n) && (0 <= ny && ny < n)) // �� ���� üũ
			{
				if (isVisited[nx][ny] == false && map[nx][ny] == '1') // �湮���ο� �������翩�� üũ
				{
					q.push({ nx,ny });
					isVisited[nx][ny] = true;
					cnt++;
				}
			}
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> map[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == '1' && isVisited[i][j] == false)
			{
				// ���� 1�� ������ ã�� ���� ���ǽ�
				// ���� 1�� ã���� �ٽ� bfs ȣ��
				cnt = 0;
				bfs(i, j);
				result.emplace_back(cnt);
			}
		}
	}
}