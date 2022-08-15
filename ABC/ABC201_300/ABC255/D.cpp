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
    for(ll &a : A) {
        cin >> a;
    }
    vector<ll> X(Q);
    for(ll &x : X) {
        cin >> x;
    }
    sort(ALL(A));
    vector<ll> csum(N + 1, 0);
    for(ll i = 0; i < N; i++) {
        csum.at(i + 1) = csum.at(i) + A.at(i);
    }
    for(ll i = 0; i < Q; i++) {
        ll index = lower_bound(ALL(A), X.at(i)) - A.begin();
        if(index == 0) {
            cout << csum.at(N) - X.at(i) * N << endl;
        } else {
            cout << X.at(i) * index - csum.at(index) + (csum.at(N) - csum.at(index)) - X.at(i) * (N - index) << endl;
        }
    }
    return 0;
}