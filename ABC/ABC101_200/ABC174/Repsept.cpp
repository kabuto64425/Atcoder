#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll K;
    cin >> K;
    ll x = 7;
    ll ans = -1;
    for(ll i = 1; i <= K; i++) {
        x = x % K;
        if(x == 0) {
            ans = i;
            break;
        }
        x = 10 * x + 7;
    }
    cout << ans << endl;
}