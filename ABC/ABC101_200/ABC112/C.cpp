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

ll centerHeight(ll cx, ll cy, const tuple<ll, ll, ll> elm) {
    ll dx = abs(cx - get<0>(elm));
    ll dy = abs(cy - get<1>(elm));
    ll H = get<2>(elm) + dx + dy;
    return H;
}

int main(){
    ll N;
    cin >> N;
    vector<tuple<ll, ll, ll>> xyh(N);
    for(tuple<ll, ll, ll> &elm : xyh) {
        cin >> get<0>(elm) >> get<1>(elm) >> get<2>(elm);
    }
    for(ll cx = 0; cx <= 100; cx++) {
        for(ll cy = 0; cy <= 100; cy++) {

            ll H = INF;
            for(ll i = 1; i < N; i++) {
                H = min(H, centerHeight(cx, cy, xyh.at(i)));
            }

            bool flag = true;

            for(ll i = 0; i < N; i++) {
                tuple<ll, ll, ll> elm = xyh.at(i);
                ll dx = abs(cx - get<0>(elm));
                ll dy = abs(cy - get<1>(elm));
                if(H - dx - dy < 0 and get<2>(elm) == 0) {
                    continue;
                }
                if(H != centerHeight(cx, cy, xyh.at(i))) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                cout << cx << " " << cy << " " << H << endl;
                return 0;
            }
        }
    }
    return 0;
}