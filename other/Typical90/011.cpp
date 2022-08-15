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

    ll ans = 0;

    for(ll bit = 0; bit < (1 << N); bit++) {
        vector<tuple<ll, ll, ll>> tasks;
        for(ll i = 0; i < N; i++) {
            if(bit & (1 << i)) {
                tasks.push_back(DCS.at(i));
            }
        }
        sort(tasks.begin(), tasks.end(), sort_by);
        ll days = 0;
        ll reward = 0;
        bool flag = true;
        for(ll i = 0; i < (ll)tasks.size(); i++) {
            if(days + get<1>(tasks.at(i)) > get<0>(tasks.at(i))) {
                flag = false;
                break;
            }
            days += get<1>(tasks.at(i));
            reward += get<2>(tasks.at(i));
        }
        if(flag) {
            ans = max(ans, reward);
        }
    }

    cout << ans << endl;
    return 0;
}