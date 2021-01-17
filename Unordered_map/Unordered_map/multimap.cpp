#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_multimap <int, int> temp;

	temp.emplace(1, 0);
	temp.emplace(1, 1);
	temp.emplace(1, 2);
	temp.emplace(1, 3);
	
	//cout << temp.find(pair<1,0>)


}