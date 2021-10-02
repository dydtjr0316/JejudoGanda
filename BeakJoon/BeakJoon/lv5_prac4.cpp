#include<iostream>
#include<unordered_set>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int arr[10];
	unordered_set<int> check;
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
		arr[i] %= 42;
		check.emplace(arr[i]);
	}
	cout << check.size() << endl;



	return 0;
}