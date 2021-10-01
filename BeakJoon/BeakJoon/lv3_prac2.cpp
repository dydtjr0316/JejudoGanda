#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int cnt, lv, rv;
	vector<int> answer;


	for (int i = 0; i < cnt; ++i)
	{
		cin >> lv >> rv;
		answer.emplace_back(lv + rv);
	}
	for (auto& obj : answer)
	{
		cout << obj << endl;
	}
}