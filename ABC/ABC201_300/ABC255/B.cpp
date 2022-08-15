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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(K);
    for(ll i = 0; i < K; i++) {
        cin >> A.at(i);
    }
    vector<ll> X(N) , Y(N);
    for(ll i = 0; i < N; i++) {
        cin >> X.at(i) >> Y.at(i);
    }
    vector<bool> l(N);
    for(ll i = 0; i < K; i++) {
        l.at(A.at(i) - 1) = true;
    }
    vector<ll> v(N, INF);
    for(ll i = 0; i < N; i++) {
        if(l.at(i)) {
            for(ll j = 0; j < N; j++) {
                ll x1 = X.at(i);
                ll y1 = Y.at(i);
                ll x2 = X.at(j);
                ll y2 = Y.at(j);
                ll d = abs(x2 - x1) * abs(x2 - x1) + abs(y2 - y1) * abs(y2 - y1);
                chmin(v.at(j), d);
            }
        }
    }
    ll ma =  *max_element(ALL(v));
    cout << fixed << setprecision(20) <<sqrtl(ma) << endl;
    return 0;
}