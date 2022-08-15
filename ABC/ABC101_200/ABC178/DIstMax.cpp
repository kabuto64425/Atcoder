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

int main(){
    ll N;
    cin >> N;
    vector<pair<ll, ll>> xy(N);
    for(pair<ll, ll> &elm : xy) {
        cin >> elm.first >> elm.second;
    }
    ll ma1 = 0;
    ll mi1 = INF;
    for(const pair<ll, ll> &elm : xy) {
        ma1 = max(ma1, elm.first + elm.second);
        mi1 = min(mi1, elm.first + elm.second);
    }

    vector<pair<ll, ll>> movementedxy = xy;
    for(pair<ll, ll> &elm : movementedxy) {
        elm.first = -elm.first;
    }
    ll ma2 = 0;
    ll mi2 = INF;
    for(const pair<ll, ll> &elm : movementedxy) {
        ma2 = max(ma2, elm.first + elm.second);
        mi2 = min(mi2, elm.first + elm.second);
    }

    cout << max(ma1 - mi1, ma2 - mi2) << endl;
    return 0;
}