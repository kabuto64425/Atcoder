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
    ll N, K, Q;
    cin >> N >> K >> Q;
    vector<ll> A(K);
    for(ll i = 0; i < K; i++) {
        cin >> A.at(i);
    }
    vector<ll> L(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> L.at(i);
    }
    for(ll i = 0; i < Q; i++) {
        ll l = L.at(i);
        l--;
        if(A.at(l) == N) {
            continue;
        }
        if(l < K - 1 and A.at(l) + 1 == A.at(l + 1)) {
            continue;
        }
        A.at(l)++;
    }
    for(ll i = 0; i < K; i++) {
        cout << A.at(i) << " ";
    }
    cout << endl;
    return 0;
}