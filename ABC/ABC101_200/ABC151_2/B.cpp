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
    ll N, K, M;
    cin >> N >> K >> M;
    vector<ll> A(N - 1);
    for(ll &a : A) {
        cin >> a;
    }
    ll sum = accumulate(ALL(A), 0LL);
    ll need = M * N;
    need -= sum;
    if(need > K) {
        cout << -1 << endl;
        return 0;
    }
    cout << max(need, 0LL) << endl;
    return 0;
}