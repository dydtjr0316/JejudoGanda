#include<iostream>
#include<vector>
using namespace std;
long long sum(std::vector<int>& a)
{
	long long result = 0;
	for (auto& obj : a)
	{
		result += obj;
	}
	return result;
};
int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	return 0;
}