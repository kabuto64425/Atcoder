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

char recur(ll t, ll k, const string &S) {
    if(t == 0) {
        return S.at(k);
    }
    if(k == 0) {
        ll num = (ll)(S.at(0) - 'A');
        num += t;
        num %= 3;
        return (char)('A' + num);
    }
    if(k % 2 == 0) {
        char c = recur(t - 1, k / 2, S);
        ll num = (ll)(c - 'A');
        num += 1;
        num %= 3;
         return (char)('A' + num);
    } else {
        char c = recur(t - 1, k / 2, S);
        ll num = (ll)(c - 'A');
        num += 2;
        num %= 3;
        return (char)('A' + num);
    }
}

int main(){
    string S;
    cin >> S;
    ll Q;
    cin >> Q;
    vector<ll> t(Q), k(Q);
    for(ll i = 0; i < Q; i++){
        cin >> t.at(i) >> k.at(i);
    }
    for(ll i = 0; i < Q; i++) {
        cout << recur(t.at(i), k.at(i) - 1, S) << endl;
    }
    return 0;
}