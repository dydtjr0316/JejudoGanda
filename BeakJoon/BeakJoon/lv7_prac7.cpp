#include<iostream>
#include <algorithm>
using namespace std;
// 1�� 13��
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
// ���۸� �غôµ� ���� �Ӱ����ߵ��ư��»����� ������
// �˰��� - reverse�Լ� �Ƚᵵ ����� Ǯ �� �ִ� ����
// �Ƚ�� �޸� ȿ�� �߳��õ�
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