#include<iostream>
using namespace std;
int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string str;
	int alpha[26];
	for (int i = 0; i < 26; i++)
		alpha[i] = -1;

	cin >> str;

	for (int i = 0; i < 26; i++)
	{
		alpha[i] = str.find((char)i+97);
	}
	for (int i = 0; i < 26; i++)
		cout << alpha[i] << " ";
	

	return 0;
}