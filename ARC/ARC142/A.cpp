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
    if(K % 10 == 0) {
        cout << 0 << endl;
        return 0;
    }
    string S = to_string(K);
    reverse(ALL(S));
    ll RK = stoll(S);
    if(RK < K) {
        cout << 0 << endl;
        return 0;
    }

    set<ll> s;
    ll current = K;
    while(current <= N) {
        s.insert(current);
        current *= 10;
    }
    current = RK;
    while(current <= N) {
        s.insert(current);
        current *= 10;
    }
    cout << s.size() << endl;
    return 0;
}