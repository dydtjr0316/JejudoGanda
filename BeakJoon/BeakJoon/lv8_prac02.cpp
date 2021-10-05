#include<iostream>

using namespace std;
// 시간 초과\
// 공식은 알아냈는데 효율적으로 바꾸는 작업을 못함
int main(void) {
    int n;
    int cnt = 1;        
    int range = 1;
    cin >> n;
    while (1) {
        if (range >= n) break;
        cnt++; 
        range += (6 * cnt);
    }
    cout << cnt;
    return 0;
}
