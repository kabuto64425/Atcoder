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
    ll N, W;
    cin >> N >> W;
    vector<tuple<ll, ll, ll>> STP(N);
    for(auto &stp : STP) {
        cin >> get<0>(stp) >> get<1>(stp) >> get<2>(stp);
    }
    vector<ll> sum(210000, 0);
    for(auto &stp : STP) {
        sum[get<0>(stp)] += get<2>(stp);
        sum[get<1>(stp)] -= get<2>(stp);
    }
    ll ma = sum[0];
    for(ll i = 1; i <= 200000; i++) {
        sum[i] += sum[i - 1];
        ma = max(ma, sum[i]);
    }
    if(ma > W) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}