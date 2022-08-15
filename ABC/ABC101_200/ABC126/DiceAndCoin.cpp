#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;

    ll x = N;
    ll y = K;
    ll count = 0;

    long double ans = 0;
    while(true) {
        //cout << y << endl;

        ll num = 0;
        if(x >= y) {
            num = x - y + 1;
            x -= num;
        } 

        ans += (num / (long double) N) / pow(2, count);

        if(y <= 1) {
            break;
        }
        y = (y + 1) / 2;
        count++;
    }

    cout << fixed << setprecision(20) << ans << endl;
}