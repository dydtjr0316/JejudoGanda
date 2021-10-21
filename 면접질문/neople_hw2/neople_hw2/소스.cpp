#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>
#include <deque>
using namespace std;
enum class T{EMPTY, EXIST, LOCK};
#define my	48
int main()
{
	list<pair<string, int>> temp(10);
	vector<T> m_slot(10, T::LOCK);
	m_slot.resize(20);

	cout << m_slot.size() << endl;
	for (auto obj : m_slot)
	{
		if (obj == T::LOCK)cout << "lock" << endl;
		else if (obj == T::EMPTY)cout << "´Ù¸¥°Å" << endl;
	}
	

	deque<T> slot;
}