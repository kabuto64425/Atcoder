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
    vector<ll> a(M), b(M);
    for(ll i = 0; i < M; i++) {
        cin >> a.at(i) >> b.at(i);
        a.at(i)--;
        b.at(i)--;
    }
    
    ll ans = 0;
    for(ll i = 0; i < M; i++) {
        dsu d(N);
        for(ll j = 0; j < M; j++) {
            if(i == j) {
                continue;
            }
            d.merge(a.at(j), b.at(j));
        }
        if(!d.same(a.at(i), b.at(i))) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}