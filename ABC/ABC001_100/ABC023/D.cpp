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

bool solve(const ll mid, const ll N, vector<pair<ll, ll>> &HS) {
    vector<ll> times(N);
    for(ll i = 0; i < N; i++) {
        ll h = HS.at(i).first;
        ll mod = ((mid - h) % HS.at(i).second + HS.at(i).second) % HS.at(i).second;
        ll time = (mid - h - mod) / HS.at(i).second;
        times.at(i) = time;
    }
    sort(times.begin(), times.end());
    for(ll i = 0; i < N; i++) {
        if(times.at(i) < i) {
            return false;
        }
    }
    return true;
}

int main(){
    ll N;
    cin >> N;
    vector<pair<ll, ll>> HS(N);
    for(pair<ll, ll> &hs : HS) {
        cin >> hs.first >> hs.second;
    }

    ll ok = INF;
    ll ng = -1;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if(solve(mid, N, HS)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}