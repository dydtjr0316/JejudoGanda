#include<iostream>
#include <set>
#include<algorithm>

using namespace std;

int main(void)	// 내가한거 120ms
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	int* arr;
	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << *min_element(arr, arr + n) << " " << *max_element(arr, arr + n) << "\n";



	return 0;
}	
int main() {	//구글링 184ms

	ios_base::sync_with_stdio(0);

	int N;
	cin >> N;

	int* array = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> array[i];
	}

	sort(array, array + N);		// 0 ~ N-1 범위 정렬

	cout << array[0] << " " << array[N - 1];

	return 0;

}