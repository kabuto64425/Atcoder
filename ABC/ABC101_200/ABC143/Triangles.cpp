#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> L(N);
    for(ll i = 0; i < N; i++) {
        cin >> L.at(i);
    }

    sort(L.begin(), L.end());

    ll ans = 0;

    for(ll a = 0; a < N - 2; a++) {
        for(ll b = a + 1; b < N - 1; b++) {
            ll c = lower_bound(L.begin(), L.end(), L.at(a) + L.at(b)) - L.begin();
            ans += (c - 1 - b);
        }
    }

    cout << ans << endl;
}