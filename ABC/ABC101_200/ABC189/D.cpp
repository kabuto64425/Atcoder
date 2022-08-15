#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

ll pow_self_made(ll n, ll x) {
    ll res = 1;
    for(ll i = 0; i < x; i++) {
        res *= n;
    }
    return res;
}

ll recur(ll n, const vector<string> S) {
    if(n < 0) {
        return 1;
    }
    if(S.at(n) == "AND") {
        return recur(n - 1, S);
    }
    return pow_self_made(2, n + 1) + recur(n - 1, S);
}

int main(){
    ll N;
    cin >> N;
    vector<string> S(N);
    for(string &s : S) {
        cin >> s;
    }

    cout << recur(N - 1, S) << endl;
    return 0;
}