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

int main(){
    ll t, N;
    cin >> t >> N;
    vector<bool> exist(101 + t, false);
    for(ll i = 1; i <= 100; i++) {
        exist.at(i * (100 + t) / 100) = true;
    }
    vector<ll> v;
    for(ll i = 1; i <= 100 + t; i++) {
        if(!exist.at(i)) {
            v.push_back(i);
        }
    }
    ll x = v.size();
    ll y = (N - 1) % x + 1;
    ll cycle = (N - 1) / x;
    cout << (100 + t) * cycle + v.at(y - 1) << endl;
    return 0;
}