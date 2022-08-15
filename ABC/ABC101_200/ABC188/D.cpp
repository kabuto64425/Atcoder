#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    ll C;
    cin >> N >> C;
    vector<tuple<ll, ll, ll>> abc(N);
    ll day = 0;
    for(auto &elm : abc) {
        cin >> get<0>(elm) >> get<1>(elm) >> get<2>(elm);
        day = max(day, get<1>(elm));
    }
    vector<pair<ll, ll>> event;
    for(ll i = 0; i < N; i++) {
        event.push_back({get<0>(abc.at(i)), get<2>(abc.at(i))});
        event.push_back({get<1>(abc.at(i)) + 1, -get<2>(abc.at(i))});
    }
    sort(event.begin(), event.end());
    
    ll current = 0;
    ll ans = 0;
    for(ll i = 0; i < event.size() - 1; i++) {
        ll day = event.at(i + 1).first - event.at(i).first;
        current += event.at(i).second;
        ans += day * min(current, C);
    }
    cout << ans << endl;
    return 0;
}