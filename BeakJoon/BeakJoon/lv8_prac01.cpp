#include<iostream>

using namespace std;
//3분컷 조건에 대해 제대로 이해하면 더빨리 풀 수도 있었음 

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int a, b, c;
	int i = 0;
	cin >> a >> b >> c;

	if (b >= c)cout << "-1";
	else cout<< a / (c - b) + 1;
	return 0;
}