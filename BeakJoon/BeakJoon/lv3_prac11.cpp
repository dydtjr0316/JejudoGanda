#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, x, num;
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num < x)cout << num << " ";
	}
	return 0;
}