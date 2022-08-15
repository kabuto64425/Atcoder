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
    vector<ll> a(N), b(N);
    for(ll i = 0; i < N; i++) {
        cin >> a.at(i) >> b.at(i);
    }
    vector<ll> c(M), d(M);
    for(ll i = 0; i < M; i++) {
        cin >> c.at(i) >> d.at(i);
    }
    for(ll i = 0; i < N; i++) {
        ll ans = INF;
        ll current = INF;
        for(ll j = 0; j < M; j++) {
            if(current > abs(c.at(j) - a.at(i)) + abs(d.at(j) - b.at(i))) {
                ans = j + 1;
                current = abs(c.at(j) - a.at(i)) + abs(d.at(j) - b.at(i));
            }
        }
        cout << ans << endl;
    }
    return 0;
}