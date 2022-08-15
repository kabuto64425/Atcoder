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
    ll H, W;
    cin >> H >> W;
    vector<ll> isRed(H * W, false);
    dsu d(H * W);
    ll Q;
    cin >> Q;
    for(ll i = 0 ; i < Q; i++) {
        ll t;
        cin >> t;
        if(t == 1) {
            pair<ll, ll> rc;
            cin >> rc.first >> rc.second;
            ll position = (rc.first - 1) * W + (rc.second - 1);
            isRed.at(position) = true;
            // 上
            if(rc.first >= 2 and isRed.at(position - W)) {
                d.merge(position, position - W);
            }
            // 下
            if(rc.first <= H - 1 and isRed.at(position + W)) {
                d.merge(position, position + W);
            }
            // 左
            if(rc.second >= 2 and isRed.at(position - 1)) {
                d.merge(position, position - 1);
            }
            // 右
            if(rc.second <= W - 1 and isRed.at(position + 1)) {
                d.merge(position, position + 1);
            }
        } else {
            pair<ll, ll> raca;
            pair<ll, ll> rbcb;
            cin >> raca.first >> raca.second >> rbcb.first >> rbcb.second;
            ll postionA = (raca.first - 1) * W + (raca.second - 1);
            ll postionB = (rbcb.first - 1) * W + (rbcb.second - 1);
            if(isRed.at(postionA) and isRed.at(postionB) and d.same(postionA, postionB)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}