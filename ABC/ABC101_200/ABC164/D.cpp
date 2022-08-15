#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

// xのn乗%modを計算
ll mod_pow(ll x, ll n, ll mod){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res*x%mod;
        x = x*x%mod;
        n >>= 1;
    }
    return res;
}

int main(){
    string S;
    cin >> S;
    vector<ll> bucket(2019);
    ll x = 0;
    bucket.at(0)++;
    ll N = S.length();
    for(ll i = 0; i < N; i++) {
        ll y = S.at(N - i - 1) - '0';
        x += mod_pow(10, i, 2019) * y;
        x = x % 2019;
        bucket.at(x)++;
    }
    ll ans = 0;
    for(ll i = 0; i < 2019; i++) {
        ans += bucket.at(i) * (bucket.at(i) - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}