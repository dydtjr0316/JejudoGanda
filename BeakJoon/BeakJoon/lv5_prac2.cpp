#include<iostream>
using namespace std;

int main()
{
	int arr[9];
	int max = 0, index = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		if (max < arr[i])
		{
			max = arr[i];
			index = i;
		}
	}
	cout << max << "\n"<<index+1;

}
// 처음 내가쓴답 왜 안되노 시발
	/*cout<<*max_element(arr, arr + 9)<<"\n";
	cout << ((int)max_element(arr, arr + 9)- (int)&arr)/4 +1<< endl;*/

