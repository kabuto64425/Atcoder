#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

void recur(ll x, ll d, vector<ll> &lunlun) {
    lunlun.push_back(x);
    if(d == 10) {
        return;
    }
    
    if(x % 10 != 0) {
        recur(x * 10 + x % 10 - 1, d + 1, lunlun);
    }
    recur(x * 10 + x % 10, d + 1, lunlun);
    if(x % 10 != 9) {
        recur(x * 10 + x % 10 + 1, d + 1, lunlun);
    }
}

signed main(){
    ll K;
    cin >> K;
    vector<ll> lunlun;
    recur(1, 1, lunlun);
    recur(2, 1, lunlun);
    recur(3, 1, lunlun);
    recur(4, 1, lunlun);
    recur(5, 1, lunlun);
    recur(6, 1, lunlun);
    recur(7, 1, lunlun);
    recur(8, 1, lunlun);
    recur(9, 1, lunlun);
    sort(lunlun.begin(), lunlun.end());
    cout << lunlun.at(K - 1) << endl;
}