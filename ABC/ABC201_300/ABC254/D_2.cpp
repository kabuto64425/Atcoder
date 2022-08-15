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

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<ll> v(N + 1);
    vector<ll> sq;
    for(ll i = 1; i * i <= N; i++) {
        sq.push_back(i * i);
    }
    reverse(ALL(sq));
    for(ll i = 1; i <= N; i++) {
        ll x = i;
        for(ll j = 0; j < sq.size(); j++) {
            if(x % sq.at(j) == 0) {
                x /= sq.at(j);
                break;
            }
        }
        v.at(x)++;
    }
    ll ans = 0;
    for(ll i = 1; i <= N; i++) {
        ans += v.at(i) * v.at(i);
    }
    cout << ans << endl;
    return 0;
}