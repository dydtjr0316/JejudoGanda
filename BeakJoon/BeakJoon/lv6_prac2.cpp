#include<iostream>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	bool num[10036]{ false, };

	for (int i = 0; i <= 10000; i++)
	{
		num[i + i / 1000 + i % 1000 / 100 + i % 100 / 10 + i % 10] = true;
	}
	
	for (int i = 0; i <= 10000; i++)
	{
		if (!num[i])cout << i << "\n";
	}


	return 0;
}