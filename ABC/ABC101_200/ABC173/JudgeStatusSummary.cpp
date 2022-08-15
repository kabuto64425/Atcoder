#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

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

signed main(){
    ll N;
    cin >> N;
    vector<string> S(N);
    REP(i, N) {
        cin >> S.at(i);
    }
    map<string, ll> ma;
    REP(i, N) {
        ma[S.at(i)]++;
    }
    cout << "AC x " << ma["AC"] << endl;
    cout << "WA x " <<ma["WA"] << endl;
    cout << "TLE x " <<ma["TLE"] << endl;
    cout << "RE x " <<ma["RE"] << endl;
}