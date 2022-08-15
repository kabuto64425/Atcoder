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
    vector<ll> field(9001, 0);
    for(const pair<ll, ll> &lr : LR) {
        ll m = 0;
        for(ll i = lr.first; i <= lr.second; i++) {
            m = max(m, field.at(i));
        }
        m += 1;
        cout << m << endl;
        for(ll i = lr.first; i <= lr.second; i++) {
            field.at(i) = m;
        }
    }
    return 0;
}