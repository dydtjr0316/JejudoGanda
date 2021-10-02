#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int a, b, c, count[10] = { 0, };
	int mul;
	cin >> a >> b >> c;

	mul = a * b * c;
	
	while(mul!=0)
	{
		count[mul % 10]++;
		mul /= 10;
	}

	for (int i = 0; i < 10; i++)
		cout << count[i] << "\n";


	return 0;
}