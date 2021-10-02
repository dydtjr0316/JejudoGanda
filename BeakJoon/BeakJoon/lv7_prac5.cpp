#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 20분 ㅅㅂ 효율찾다가 시간너무씀
bool cmp(int a, int b) {
	return a > b;
}
int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string str;
	int max = 0, max_index = 0;
	char c;
	vector<int> count;
	for (int i = 0; i < 26; i++)
		count.emplace_back(0);
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (str[i] == (char)(j + 97) || str[i] == (char)(j + 97 - 32))
			{
				count[j]++;
				break;
			}
		}
	}
	for (int i = 0; i < count.size(); i++)
	{
		if (max < count[i]) {
			max = count[i];
			max_index = i;
		}
	}

	sort(count.begin(), count.end(), cmp);
	if (count[0] == count[1])cout << "?";
	else cout << (char)(max_index + 97 - 32);

	return 0;
}