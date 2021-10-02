#include<iostream>
using namespace std;
// 3Ка 43УЪ 
int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, t;
	string str;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t >> str;
		for (int j = 0; j < str.size(); j++)
		{
			for (int k = 0; k < t; k++)
			{
				cout << str[j];
			}
		}
		cout << "\n";
	}

	return 0;
}