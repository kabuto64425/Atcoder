#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N; 
    ll K;
    cin >> N >> K;
    vector<vector<ll>> next(60, vector<ll>(N));
    for (ll v = 0; v < N; ++v) cin >> next[0][v], --next[0][v];
    for (ll d = 0; d + 1 < 60; ++d) {
        for (ll v = 0; v < N; ++v) {
            next[d+1][v] = next[d][next[d][v]];
        }
    }
    ll v = 0;
    for (ll d = 0; d < 60; ++d) {
        if (K & (1LL<<d)) v = next[d][v];
    }
    cout << v + 1 << endl;
}