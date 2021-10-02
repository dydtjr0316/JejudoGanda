#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	float n, max_score, sum = 0;
	cin >> n;
	float score;
	vector<float> scores;

	for (int i = 0; i < n; i++)
	{
		cin >> score;
		scores.push_back(score);
	}
	max_score = *max_element(scores.begin(), scores.end());

	for (int i = 0; i < n; i++)
	{
		sum += scores[i]/max_score*100;
	}

	cout << sum / n;

	return 0;
}
