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

bool sort_by_second(pair<ll, ll> a, pair<ll, ll> b) {
    return a.second < b.second;
}

int main(){
    ll N;
    cin >> N;
    vector<pair<ll, ll>> XL(N);
    for(pair<ll, ll> &xl : XL) {
        cin >> xl.first >> xl.second;
    }
    vector<pair<ll, ll>> ranges(N);
    for(ll i = 0; i < N; i++) {
        ranges[i].first = XL[i].first - XL[i].second;
        ranges[i].second = XL[i].first + XL[i].second;
    }
    sort(ranges.begin(), ranges.end(), sort_by_second);
    ll ans = N;
    ll current = -INF;
    for(ll i = 0; i < N; i++) {
        if(ranges.at(i).first < current) {
            ans--;
        } else {
            current = ranges.at(i).second;
        }
    }
    cout << ans << endl;
    return 0;
}