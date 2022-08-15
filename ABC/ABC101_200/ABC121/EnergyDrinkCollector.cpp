#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> AB(N);
    REP(i, N) {
        cin >> AB.at(i).first >> AB.at(i).second;
    }
    sort(AB.begin(), AB.end());

    ll ans = 0;
    ll count = 0;
    ll i = 0;

    while(count + AB.at(i).second < M) {
        ans += AB.at(i).first * AB.at(i).second;
        count += AB.at(i).second;
        i++;
    }
    ans += AB.at(i).first * (M - count);

    cout << ans << endl;
}