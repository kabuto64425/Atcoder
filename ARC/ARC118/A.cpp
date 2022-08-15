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

int main(){
    ll t, N;
    cin >> t >> N;
    vector<ll> bucket(101 + t, 0);
    for(ll i = 1; i <= 100; i++) {
        ll x = (i * (100 + t)) / ((long double) 100);
        bucket.at(x)++;
    }
    vector<ll> cycle;
    for(ll i = 1; i <= 100 + t; i++) {
        if(bucket.at(i) == 0) {
            cycle.push_back(i);
        }
    }
    cout << (100 + t) * ((N - 1) / cycle.size()) + cycle.at((N - 1) % cycle.size()) << endl;
    return 0;
}