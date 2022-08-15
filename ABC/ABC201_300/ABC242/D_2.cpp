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
        ll index = ((ll)(c - 'A') + t) % 3;
        return 'A' + index;
    }
    char c = recur(S, t - 1, k / 2);
    if(k % 2 == 0) {
        ll index = ((ll)(c - 'A') + 1) % 3;
        return 'A' + index;
    }
    ll index = ((ll)(c - 'A') + 2) % 3;
    return 'A' + index;
}

int main(){
    string S;
    cin >> S;
    ll Q;
    cin >> Q;
    vector<ll> t(Q), k(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> t.at(i) >> k.at(i);
        k.at(i)--;
    }
    for(ll i = 0; i < Q; i++) {
        cout << recur(S, t.at(i), k.at(i)) << endl;
    }
    return 0;
}