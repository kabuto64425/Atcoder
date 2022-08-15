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

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

// xのn乗%modを計算
mint mod_pow(ll x, ll n){
    mint res = 1;
    while(n > 0){
        res *= x;
        n--;
    }
    return res;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> D(N);
    for(ll i = 0; i < N; i++) {
        cin >> D.at(i);
    }
    vector<ll> bucket(110000, 0);
    ll m = 0;
    for(ll i = 0; i < N; i++) {
        bucket.at(D.at(i))++;
        m = max(m, D.at(i));
    }

    if(bucket.at(0) != 1 or D.at(0) != 0) {
        cout << 0 << endl;
        return 0;
    }

    mint ans = 1;

    for(ll i = 1; i <= m; i++) {
        if(bucket.at(i - 1) == 0) {
            ans *= 0;
        } else {
            ans *= mod_pow(bucket.at(i - 1), bucket.at(i));
        }
    }

    cout << ans.val() << endl;
    return 0;
}