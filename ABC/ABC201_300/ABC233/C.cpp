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

void dfs(ll rest, ll current, const vector<ll> &L, const vector<vector<ll>> &a, ll &ans) {
    if(rest == 0) {
        if(current == 1) {
            ans++;
        }
        return;
    }

    for(ll i = 0; i < L.at(rest - 1); i++) {
        if(current % a.at(rest - 1).at(i) != 0) {
            continue;
        }
        ll devided = current / a.at(rest - 1).at(i);
        dfs(rest - 1, devided, L, a, ans);
    }
}

int main(){
    ll N, X;
    cin >> N >> X;
    vector<ll> L(N);
    vector<vector<ll>> a(N);
    for(ll i = 0; i < N; i++) {
        cin >> L.at(i);
        for(ll j = 0; j < L.at(i); j++) {
            ll elm;
            cin >> elm;
            a.at(i).push_back(elm);
        }
    }
    ll ans = 0;
    dfs(N, X, L, a, ans);
    cout << ans << endl;
    return 0;
}