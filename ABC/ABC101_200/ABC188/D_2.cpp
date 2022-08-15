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
    ll N, C;
    cin >> N >> C;
    vector<tuple<ll, ll, ll>> abc(N);
    for(auto &elm : abc) {
        cin >> get<0>(elm) >> get<1>(elm) >> get<2>(elm);
    }
    vector<tuple<ll, ll, ll>> vec;
    for(auto &elm : abc) {
        vec.push_back({get<0>(elm), get<2>(elm), 0});
        vec.push_back({get<1>(elm) + 1, -get<2>(elm), 0});
    }

    sort(vec.begin(), vec.end());
    for(ll i = 0; i < vec.size(); i++) {
        get<2>(vec.at(i)) = i;
    }
    return 0;
}