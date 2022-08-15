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

    ll ans = vec.at(0);
    for(ll i = 1; i < N; i++) {
        ans = gcd(ans, vec.at(i));
    }

    cout << ans << endl;
}