#include<iostream>
#include<set>
#include <string>
using namespace std;
int solution(int p)
{
	set<char>str;
	string temp = to_string(p);
	int firstsize = temp.size();
	
	str.insert(temp.begin(), temp.end());
	do {
		p++;
		str.clear();
		temp = to_string(p);
		for (auto& obj : temp)str.emplace(obj);
		
	} while (str.size() != firstsize && str.size() != firstsize + 1);
	return p;
}
int main()
{
	solution(1987);
}