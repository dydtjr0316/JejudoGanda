#include<iostream>

using namespace std;
// �ð� �ʰ�\
// ������ �˾Ƴ´µ� ȿ�������� �ٲٴ� �۾��� ����
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