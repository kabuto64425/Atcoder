#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    ll limit = sqrt(N);
    ll ans = -1;
    for(ll i = 1; i <= limit; i++) {
        if(N % i == 0) {
            ll x = i;
            ll y = N / i;
            if(ans == -1) {
                ans = x + y - 2;
            } else {
                ans = min(ans, x + y - 2);
            }
            
        }
    }
    cout << ans << endl;
}