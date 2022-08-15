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
    vector<ll> X(N), Y(N);
    for(ll i = 0; i < N ; i++) {
        cin >> X.at(i) >> Y.at(i);
    }
    ll ans = 0;
    for(ll i = 0; i < N - 2; i++) {
        for(ll j = i + 1; j < N - 1; j++) {
            for(ll k = j + 1; k < N ; k++) {
                ll x1 = X.at(i);
                ll y1 = Y.at(i);

                ll x2 = X.at(j);
                ll y2 = Y.at(j);

                ll x3 = X.at(k);
                ll y3 = Y.at(k);

                pair<ll, ll> v1 = {x1 - x3, y1 - y3};
                pair<ll, ll> v2 = {x2 - x3, y2 - y3};
                if(v1.first * v2.second != v1.second * v2.first) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}