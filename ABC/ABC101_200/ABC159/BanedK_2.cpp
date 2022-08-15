#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> bucket(N + 1, 0);
    for(ll &a : A) {
        cin >> a;
        bucket.at(a)++;
    }
    ll ans = 0;
    for(const ll &b : bucket) {
        ans += b * (b - 1) / 2;
    }
    for(const ll &a : A) {
        cout << ans - max(0LL, bucket.at(a) - 1) << endl;
    }
    return 0;
}