#include<iostream>
#include<algorithm>
#include <string>
using namespace std;
int sum(int n)
{
	int ans = 0;
	while (n!=0)
	{
		ans += n % 10;
		n = n / 10;
	}
	if (ans / 10 != 0)return sum(ans);
	return ans;
}
int solution(int n)
{
	int ans = 0;
	while (n != 0)
	{
		ans += n % 10;
		n = n / 10;
	}
	if (ans / 10 != 0)return solution(ans);
	return ans;
}
int main()
{
	solution(456789);
}S