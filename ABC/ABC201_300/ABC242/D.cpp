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

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

char recur(const string &S, ll t, ll k) {
    if(t == 0) {
        return S.at(k);
    }
    if(k == 0) {
        char c = S.at(0);
        ll x = c - 'A';
        x += t;
        x %= 3;
        return (char)('A'+ x);
    }
    char c = recur(S, t - 1, k / 2);
    ll x = c - 'A';
    if(k % 2 == 0) {
        x += 1;
        x %= 3;
    } else {
        x += 2;
        x %= 3;
    }
    return (char)('A'+ x);
}

int main(){
    string S;
    cin >> S;
    ll Q;
    cin >> Q;
    vector<ll> t(Q), k(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> t.at(i) >> k.at(i);
    }
    ll N = S.length();
    for(ll i = 0; i < Q; i++) {
        cout << recur(S, t.at(i), k.at(i) - 1) << endl;
    }
    return 0;
}