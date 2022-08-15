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
    ll N, S, D;
    cin >> N >> S >> D;
    vector<pair<ll, ll>> XY(N);
    for(pair<ll, ll> &xy : XY) {
        cin >> xy.first >> xy.second;
    }
    for(const pair<ll, ll> &xy : XY) {
        if(xy.first >= S) {
            continue;
        }
        if(xy.second <= D) {
            continue;
        }
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}