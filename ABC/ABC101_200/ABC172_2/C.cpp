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
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N), B(M);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    for(ll i = 0; i < M; i++) {
        cin >> B.at(i);
    }
    vector<ll> csumA(N + 1);
    vector<ll> csumB(M + 1);
    for(ll i = 0; i < N; i++) {
        csumA.at(i + 1) = csumA.at(i) + A.at(i);
    }
    
    for(ll i = 0; i < M; i++) {
        csumB.at(i + 1) = csumB.at(i) + B.at(i);
    }
    ll ans = 0;
    for(ll i = 0; i <= N; i++) {
        if(K - csumA.at(i) < 0) {
            break;
        }
        ll j = upper_bound(ALL(csumB), K - csumA.at(i)) - csumB.begin();
        j--;
        chmax(ans, i + j);
    }
    cout << ans << endl;
    return 0;
}