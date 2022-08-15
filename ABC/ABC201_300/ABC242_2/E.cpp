#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
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

mint solver(ll N, string &S) {
    ll half = (N + 1) / 2;
    mint ans = 0;
    for(ll i = 0; i < half; i++) {
        ll num = (ll)(S.at(i) - 'A');
        ans += (mint)(((mint)26).pow(half - 1 - i) * num);
    }
    string T = S.substr(0, N / 2);
    reverse(ALL(T));
    string U = S.substr(0, half) + T;
    if(U <= S) {
        ans++;
    }
    return ans;
}

int main(){
    ll T;
    cin >> T;
    vector<ll> N(T);
    vector<string> S(T);
    for(ll i = 0; i < T; i++) {
        cin >> N.at(i) >> S.at(i);
    }
    REP(test, T) {
        cout << solver(N.at(test), S.at(test)).val() << endl;
    }
    return 0;
}