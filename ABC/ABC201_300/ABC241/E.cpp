#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N; 
    ll K;
    cin >> N >> K;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    vector<vector<ll>> next(60, vector<ll>(N));
    vector<vector<ll>> sum(60, vector<ll>(N));
    for (ll v = 0; v < N; ++v) {
        next[0][v] = (v + A.at(v)) % N;
        sum[0][v] = A.at(v);
    }
    for (ll d = 0; d + 1 < 60; ++d) {
        for (ll v = 0; v < N; ++v) {
            next[d+1][v] = next[d][next[d][v]];
            sum[d+1][v] = sum[d][v] + sum[d][next[d][v]];
        }
    }
    ll ans = 0;
    ll v = 0;
    for (ll d = 0; d < 60; ++d) {
        if (K & (1LL<<d)) {
            ans += sum[d][v];
            v = next[d][v];
        }
    }
    cout << ans << endl;
}