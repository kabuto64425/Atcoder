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
    vector<pair<ll, ll>> ranges(N);
    for(pair<ll, ll> &range : ranges) {
        ll X, L;
        cin >> X >> L;
        range.first = X - L;
        range.second = X + L;
    }
    auto comp = [](pair<ll, ll> a, pair<ll, ll> b) {
        return a.second < b.second;
    };
    sort(ranges.begin(), ranges.end(), comp);
    ll ans = N;
    ll secondMax = -INF;
    for(pair<ll, ll> &range : ranges) {
        if(range.first < secondMax) {
            ans--;
        } else {
            secondMax = range.second;
        }
    }
    cout << ans << endl;
    return 0;
}