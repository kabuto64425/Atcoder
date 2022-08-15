#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    vector<ll> vec(N);
    for(ll i = 0; i < N; i++) {
        cin >> vec.at(i);
    }

    ll ans;
    for(ll i = 1; i <= 100; i++) {
        ll current = 0;
        for(ll j = 0; j < N; j++) {
            current += (vec.at(j) - i) * (vec.at(j) - i);
        }
        if(i == 1) {
            ans = current;
        } else {
            ans = min(ans, current);
        }
    }
    cout << ans << endl;
}