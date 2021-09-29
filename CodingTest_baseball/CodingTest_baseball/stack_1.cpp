#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	queue<int>p;
	queue<int>s;
	vector<int> ans;
	int cnt = 0;

	for (auto& obj : progresses)
		p.push(obj);
	for (auto& obj : speeds)
		s.push(obj);
	
	while (true)
	{
		p.front() += s.front();
		if (p.front() + s.front() >= 100)
		{
			p.pop();
			s.pop();
			cnt++;
		}
		else
		{
			ans.emplace_back(cnt);
			cnt = 0;
		}
	}
}
int main()
{
	vector<int> progresses{ 93,30,55 };
	vector<int> speeds{ 1,30,5 };
	solution(progresses, speeds);
}