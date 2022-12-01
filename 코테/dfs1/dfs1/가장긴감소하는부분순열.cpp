#include <iostream>
using namespace std;
int main(void) {
    int dp[7];
    int ary[7] = { 10, 30, 10, 20, 20, 10 };
    int N = 6, Max = -1;

    dp[0] = 1;

    int temp = 0;
    for (int i = 1; i < N; i++) {
        for (int j = i; j > -1; j--) {
            if (ary[i] < ary[j]) {
                if (dp[j] > temp) {
                    dp[i] = dp[j] + 1;
                    temp = dp[j];
                    Max = max(Max, dp[i]);
                }
            }
        }
        if (temp == 0)
        { dp[i] = 1; }
        temp = 0;
    }
    cout << Max;
}
