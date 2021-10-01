#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int  num, cnt = 0, next;
	cin >> num;
	if (num < 10)num *= 10;
	next = num;
	do
	{
		next = (next % 10 * 10) + (next % 10 + next / 10) % 10;
		cnt++;
	} while (num != next);

	cout << cnt;

	return 0;
}