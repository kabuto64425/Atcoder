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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    vector<ll> K(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> K.at(i);
    }
    for(ll i = 0; i < Q; i++) {
        ll k = K.at(i);
        ll ok = 1;
        ll ng = 1000000000000100001;
        while(abs(ok - ng) != 1) {
            ll mid = (ok + ng) / 2;
            ll x = lower_bound(ALL(A), mid) - A.begin();
            mid - x;
            if(mid - x <= k) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        cout << ok << endl;
    }
    return 0;
}