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
    ll H, W, N;
    cin >> H >> W >> N;
    vector<pair<ll, ll>> AB(N);
    for(pair<ll, ll> &ab : AB) {
        cin >> ab.first >> ab.second;
    }
    
    vector<ll> valsH;
    for (ll i = 0; i < N; i++) {
        valsH.push_back(AB.at(i).first);
    }

    sort(valsH.begin(), valsH.end());
    valsH.erase(unique(valsH.begin(), valsH.end()), valsH.end());

    vector<ll> valsW;
    for (ll i = 0; i < N; i++) {
        valsW.push_back(AB.at(i).second);
    }

    sort(valsW.begin(), valsW.end());
    valsW.erase(unique(valsW.begin(), valsW.end()), valsW.end());

    for (ll i = 0; i < N; i++) {
        ll h = lower_bound(valsH.begin(), valsH.end(), AB.at(i).first) - valsH.begin();
        ll w = lower_bound(valsW.begin(), valsW.end(), AB.at(i).second) - valsW.begin();

        cout << (h + 1) << " " << (w + 1) << endl;
    }

    return 0;
}