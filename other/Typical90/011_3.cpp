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

bool sort_by(tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) {
    return get<0>(a) < get<0>(b);
}

int main(){
    ll N;
    cin >> N;
    vector<tuple<ll, ll, ll>> DCS(N);
    for(tuple<ll, ll, ll> &dcs : DCS) {
        cin >> get<0>(dcs) >> get<1>(dcs) >> get<2>(dcs);
    }

    sort(DCS.begin(), DCS.end(), sort_by);

    vector<vector<ll>> dp(N + 1, vector<ll>(5001, 0));

    for(ll i = 1; i <= N; i++) {
        for(ll day = 1; day <= 5000; day++) {
            tuple<ll, ll, ll> dcs = DCS.at(i - 1);
            ll d = get<0>(dcs);
            ll c = get<1>(dcs);
            ll s = get<2>(dcs);

            if(day >= c and day <= d) {
                dp.at(i).at(day) = max(dp.at(i - 1).at(day), dp.at(i - 1).at(day - c) + s);
            } else {
                dp.at(i).at(day) = dp.at(i - 1).at(day);
            }
        }
    }

    cout << *max_element(dp.at(N).begin(), dp.at(N).end()) << endl;

    return 0;
}