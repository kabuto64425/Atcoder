#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    string S;
    cin >> S;
    ll N = S.length();

    vector<vector<ll>> next(60, vector<ll>(N));
    for (int v = 0; v < N; ++v) {
        next[0][v] = ((S.at(v) == 'R')? v + 1 : v - 1);
    }
    for (int d = 0; d + 1 < 60; ++d) {
        for (int v = 0; v < N; ++v) {
            next[d+1][v] = next[d][next[d][v]];
        }
    }
    ll K = 10000000;
    vector<ll> ans(N, 0);
    for(ll v = 0; v < N; v++) {
        ll pos = v;
        for (int d = 0; d < 60; ++d) {
            if (K & (1LL<<d)) pos = next[d][pos];
        }
        ans.at(pos)++;
    }
    for(ll i = 0; i < N; i++) {
        cout << ans.at(i) << " ";
    }
    cout << endl;
    return 0;
}