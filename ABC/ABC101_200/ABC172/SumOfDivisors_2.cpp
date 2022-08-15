#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    ll ans = 0;
    for(ll i = 1; i <= N; i++) {
        ll div = N / i;
        ans += (i + i * div) * div / 2;
    }
    cout << ans << endl;
}