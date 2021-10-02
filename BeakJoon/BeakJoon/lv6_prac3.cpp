#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n = 0, cnt = 0;
	int first, second, third;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		if (i < 100)cnt++;
		else
		{
			first = i / 100;
			second = i % 100 / 10;
			third = i % 10;
			if((first - second == second - third))cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}