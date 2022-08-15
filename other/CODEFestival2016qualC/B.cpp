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
    ll K, T;
    cin >> K >> T;
    vector<ll> a(T);
    for(ll &elm : a) {
        cin >> elm;
    }
    ll ma = *max_element(ALL(a));
    cout << max(ma - 1 - (K - ma), 0LL) << endl;
    return 0;
}