#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;

    vector<ll> vec(N);
    for(ll i = 0; i < N; i++) {
        cin >> vec.at(i);
    }

    sort(vec.begin(), vec.end());

    ll ans = 0;
    for(ll i = 0; i < N - K; i++) {
        ans += vec.at(i);
    }
    cout << ans << endl;
}