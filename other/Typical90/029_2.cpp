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
    ll W, N;
    cin >> W >> N;
    vector<pair<ll, ll>> LR(N);
    for(pair<ll, ll> &lr : LR) {
        cin >> lr.first >> lr.second;
    }

    // 座標圧縮
    vector<ll> vals;
    for(const pair<ll, ll> &lr : LR) {
        vals.push_back(lr.first);
        vals.push_back(lr.second);
    }

    sort(vals.begin(), vals.end());

    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    vector<ll> field(550000, 0);

    for(const pair<ll, ll> &lr : LR) {
        ll cl = lower_bound(vals.begin(), vals.end(), lr.first) - vals.begin();
        ll cr = lower_bound(vals.begin(), vals.end(), lr.second) - vals.begin();
        ll m = 0;
        for(ll i = cl; i <= cr; i++) {
            m = max(m, field.at(i));
        }
        m += 1;
        cout << m << endl;
        for(ll i = cl; i <= cr; i++) {
            field.at(i) = m;
        }
    }

    return 0;
}