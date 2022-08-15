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
    ll ans = 0;
    vector<ll> bucket(110000, 0);
    for(ll &a: A) {
        cin >> a;
        bucket.at(a)++;
        ans += a;
    }
    ll Q;
    cin >> Q;
    REP(i, Q) {
        ll B, C;
        cin >> B >> C;
        ans += (C - B) * bucket.at(B);
        cout << ans << endl;
        bucket.at(C) += bucket.at(B);
        bucket.at(B) = 0;
    }
    return 0;
}