#include<iostream>
#include <algorithm>
using namespace std;
// 1분 13초
int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	a > b ? cout << a : cout << b;

	return 0;
}
// 구글링 해봤는데 존나 머가리잘돌아가는새끼들 많은듯
// 알고리즘 - reverse함수 안써도 충분히 풀 수 있는 문제
// 안써야 메모리 효율 잘나올듯
int main(void) {
	string x, y;
	cin >> x >> y;

	string bigger;

	for (int i = 2; i >= 0; i--) {
		if (x[i] > y[i]) {
			bigger = x; break;
		}
		else if (x[i] < y[i]) {
			bigger = y; break;
		}
	}

	cout << bigger[2] << bigger[1] << bigger[0];
	return 0;
}