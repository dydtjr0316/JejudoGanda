#include<iostream>
#include <vector>
using namespace std;
// ��Ǯ���� ����
// �Ʒ��� ���� Ǭ��
int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string str[8] = { "c=", "c-", "dz=" , "d-" , "lj" , "nj" , "s=" , "z=" };

	string inputstr;
	int cnt = 0, i = 0;
	cin >> inputstr;
	while (true)
	{
		if (inputstr.find(str[i]) != string::npos)//�ش� ���ڿ��� �ִٸ�
		{
			inputstr.replace(inputstr.find(str[i]), str[i].length(),"0");
		}
		else
		{
			i++;
			if (i > 7)break;
		}
	}

	cout << inputstr.length();

	return 0;
}
//// ���� ���۸�
//int main() {
//	vector<string> vec = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
//	int index = 0;
//	string S;
//	cin >> S;
//	for (int i = 0; i < vec.size(); i++) {
//		index = S.find(vec[i]);
//		for (; index != string::npos; index = S.find(vec[i]))
//			S.replace(index, vec[i].length(), "@");
//	}
//	cout << S.length();
//}