#include<iostream>

using namespace std;
//3���� ���ǿ� ���� ����� �����ϸ� ������ Ǯ ���� �־��� 

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