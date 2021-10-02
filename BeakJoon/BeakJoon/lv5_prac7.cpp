#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int c, n;
	int cnt = 0, sum = 0;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> n;
		int* pscore = new int[n] {0};
		for (int k = 0; k < n; k++)
		{
			cin >> pscore[k];
			sum += pscore[k];
		}
		
		for (int j = 0; j < n; j++)
		{
			if (pscore[j] > (float)(sum / n))cnt++;
		}
		cout << fixed;
		cout.precision(3);
		cout << ((float)cnt / (float)n)*100 << "%\n";
		cnt = sum = 0;
	}


	return 0;
}
