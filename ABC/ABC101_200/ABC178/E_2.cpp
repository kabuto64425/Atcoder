#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<ll> x(N), y(N);
    for(ll i = 0; i < N; i++) {
        cin >> x.at(i) >> y.at(i);
    }
    vector<ll> rx(N), ry(N);
    for(ll i = 0; i < N; i++) {
        rx.at(i) = x.at(i) - y.at(i);
        ry.at(i) = x.at(i) + y.at(i);
    }
    ll minrx = *min_element(ALL(rx));
    ll maxrx = *max_element(ALL(rx));
    ll minry = *min_element(ALL(ry));
    ll maxry = *max_element(ALL(ry));
    cout << max(maxrx - minrx, maxry - minry) << endl;
    return 0;
}