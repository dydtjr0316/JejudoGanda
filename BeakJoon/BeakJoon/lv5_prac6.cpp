#include<iostream>

using namespace std;

//메모리 2024	4초 // 구글링
int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, cnt = 1, sum = 0;
	cin >> n;

	string* arr = new string[n];
	int* score = new int[n] {0, };

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		for (auto& obj : arr[i])
		{
			if (obj == 'O')
			{
				score[i] += cnt;
				cnt++;
			}
			else
				cnt = 1;
		}
		cnt = 1;
	}
	for (int i = 0; i < n; i++)
	{
		cout << score[i] << "\n";
	}

	return 0;
}

// 메모리 2156 0ms // 내가한거
int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, cnt = 0, sum = 0;
	string str;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (auto& obj : str)
		{
			if (obj == 'O')
			{
				cnt++;
				sum += cnt;
			}
			else
				cnt = 0;
		}
		cout << sum << endl;
		cnt = sum = 0;
	}

	return 0;
}