#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include <string>
using namespace std;

vector<int> solution(vector<int> w)
{
	vector<int> a;
	vector<int> result;
	vector<pair<int, int>> stage;
	for (int i = 0; i < w.size(); i++)
		stage.emplace_back(make_pair(i,w[i]));
	vector<pair<int, int>> win;

	while (true)
	{
		for (int i = 0; i < stage.size(); i += 2)
		{
			if (stage[i].second <= stage[i + 1].second)
				win.emplace_back(stage[i + 1]);
			else
				win.emplace_back(stage[i]);
		}
		if (win.size() == 4)break;
		stage.clear();
		for (int i = 0; i < win.size(); i++)
			stage.push_back(win[i]);
		win.clear();

	}
	for (auto& obj : win)result.emplace_back(obj.first);
	sort(result.begin(), result.end());
	return result;
}
int main()
{
	vector<int> t{ 3,2,4,5,6,2,4,5,1,2,3,4,5,6,7,8 };
	solution(t);
}