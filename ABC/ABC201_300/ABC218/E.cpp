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
    ll N, M;
    cin >> N >> M;
    vector<tuple<ll, ll, ll>> CAB(M);
    for(tuple<ll, ll, ll> &cab : CAB) {
        cin >> get<1>(cab) >> get<2>(cab) >> get<0>(cab);
        get<1>(cab)--;
        get<2>(cab)--;
    }
    sort(CAB.begin(), CAB.end());
    dsu d(N);
    ll ans = 0;
    for(ll i = 0; i < M; i++) {
        ll a = get<1>(CAB.at(i));
        ll b = get<2>(CAB.at(i));
        if(d.leader(a) != d.leader(b)) {
            d.merge(a, b);
        } else {
            if(get<0>(CAB.at(i)) > 0) {
                ans += get<0>(CAB.at(i));
            }
        }
    }
    cout << ans << endl;
    return 0;
}