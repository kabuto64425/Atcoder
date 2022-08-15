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

bool rec(ll rest, ll current, ll N, ll K, const vector<vector<ll>> T) {
    if(rest == 0) {
        if(current == 0) {
            return false;
        }
        return true;
    }
    for(ll i = 0; i < K; i++) {
        if(!rec(rest - 1, current ^ T.at(N - rest).at(i), N, K, T)) {
            return false;
        }
    }
    return true;
}

int main(){
    ll N, K;
    cin >> N >> K;
    vector<vector<ll>> T(N, vector<ll>(K));
    for(vector<ll> &t : T) {
        for(ll &elm : t) {
            cin >> elm;
        }
    }

    cout << (rec(N, 0, N, K, T)? "Nothing" : "Found") << endl;

    return 0;
}