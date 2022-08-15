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

// xのn乗%modを計算
ll mod_made(ll x, ll n){
    ll res = 1;
    REP(i, n) {
        res *= x;
    }
    return res;
}

ll recur(ll index, const vector<string> &S) {
    if(index == 0) {
        return 1;
    }
    if(S.at(index - 1) == "AND") {
        return recur(index - 1, S);
    }
    return mod_made(2, index) + recur(index - 1, S);
}

int main(){
    ll N;
    cin >> N;
    vector<string> S(N);
    for(string &s : S) {
        cin >> s;
    }

    cout << recur(N, S) << endl;
    return 0;
}