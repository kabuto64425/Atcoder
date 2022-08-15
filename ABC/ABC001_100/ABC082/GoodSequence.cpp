#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll N;
    cin >> N;
    vector<ll> x(N);

    REP(i, N) {
        cin >> x.at(i);
    }

    vector<ll> bucket(100001, 0);

    ll ans = 0;
    REP(i, N) {
        if(x.at(i) > 100000) {
            ans++;
            continue;
        }
        bucket.at(x.at(i))++;
    }

    FOR(i, 1, 100000) {
        if(bucket.at(i) > i) {
            ans += (bucket.at(i) - i);
        } else if(bucket.at(i) < i) {
            ans += bucket.at(i);
        }
    }

    cout << ans << endl;
}