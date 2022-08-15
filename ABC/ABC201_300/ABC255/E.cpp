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
    ll N, M;
    cin >> N >> M;
    vector<ll> S(N - 1);
    for(ll i = 0; i < N - 1; i++) {
        cin >> S.at(i);
    }
    vector<ll> X(M);
    for(ll i = 0; i < M; i++) {
        cin >> X.at(i);
    }
    vector<ll> B(N);
    B.at(0) = 0;
    for(ll i = 1; i < N; i++) {
        B.at(i) = S.at(i - 1) - B.at(i - 1);
    }
    map<ll, ll> m;
    for(ll i = 0, k = 1; i < N; i++, k *= -1) {
        for(ll j = 0; j < M; j++) {
            ll z = (X.at(j) - B.at(i)) * k;
            m[z]++;
        }
    }
    ll ans = 0;
    for(pair<ll, ll> key : m) {
        chmax(ans, key.second);
    }
    cout << ans << endl;
    return 0;
}