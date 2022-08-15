#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //入力
    ll X;
    cin >> X;
    ll K;
    cin >> K;
    ll D;
    cin >> D;

    //処理

    ll ans = 0;
    ll n = abs(X / D);

    if(K < n) {
        if(X < 0) {
            ans = X + K * D;
        } else {
            ans = X - K * D;
        }
    } else {
        if(X < 0) {
            if((K - n) % 2 == 0) {
                ans = X % D;
            } else {
                ans = X % D + D;
            }
        } else {
            if((K - n) % 2 == 0) {
                ans = X % D;
            } else {
                ans = X % D - D;
            }
        }
    }

    cout << abs(ans) << endl;
}