#include<iostream>
#include<string>
using namespace std;
// 8분 40초 문제 조건 똑바로보기
int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int cnt = 0;
	string str;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')cnt++;
	}
	if (*str.begin() == ' ')cnt--;
	if (*(str.end()-1) == ' ')cnt--;
	cout << cnt + 1;

	return 0;
}