#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(ll i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    ll ans = a.at(0);
    for(ll i = 1; i < N; i++) {
        ans = gcd(ans, a.at(i));
    }

    cout << ans << endl;
}