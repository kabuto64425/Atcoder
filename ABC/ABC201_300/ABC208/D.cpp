#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, M;
    cin >> N >> M;
    vector<tuple<ll, ll, ll>> ABC(M);
    for(tuple<ll, ll, ll> &abc : ABC) {
        cin >> get<0>(abc) >> get<1>(abc) >> get<2>(abc);
    }
    vector<vector<vector<ll>>> f(N + 1, vector<vector<ll>>(N + 1, vector<ll>(N + 1, INF)));
    for(ll i = 1; i <= N; i++) {
        f.at(i).at(i).at(0) = 0;
    }
    for(const tuple<ll, ll, ll> &abc : ABC) {
        f.at(get<0>(abc)).at(get<1>(abc)).at(0) = get<2>(abc);
    }
    ll ans = 0;
    for(ll k = 1; k <= N; k++) {
        for(ll s = 1; s <= N; s++) {
            for(ll t = 1; t <= N; t++) {
                f.at(s).at(t).at(k) = min(f.at(s).at(t).at(k - 1), f.at(k).at(t).at(k - 1) + f.at(s).at(k).at(k - 1));
                if(f.at(s).at(t).at(k) != INF) {
                    ans += f.at(s).at(t).at(k);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}