#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> V(N);
    for(ll &v : V) {
        cin >> v;
    }

    ll ans = 0;
    ll maxPopCount = min(N, K);

    for(ll a = 0; a <= maxPopCount; a++) {
        for(ll b = 0; b <= maxPopCount - a; b++) {
            vector<ll> poped;
            copy(V.begin(), V.begin() + a,std::back_inserter(poped));
            copy(V.end() - b, V.end(),std::back_inserter(poped));
            sort(poped.begin(), poped.end());
            ll exceptCount = K - a - b;
            ll sum = 0;
            for(ll i = 0; i < poped.size(); i++) {
                if(poped.at(i) < 0 and i < exceptCount) {
                    continue;
                }
                sum += poped.at(i);
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}