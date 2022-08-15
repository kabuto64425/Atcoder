#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, Q;
    cin >> N >> Q;
    vector<ll> x(Q), y(Q), z(Q), w(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> x.at(i) >> y.at(i) >> z.at(i) >> w.at(i);
    }
    vector<vector<bool>> vec(60, vector<bool>(Q));
    for(ll i = 0; i < 60; i++) {
        for(ll j = 0; j < Q; j++) {
            bitset<60> s(w.at(j));
            vec.at(i).at(j) = s.test(i);
        }
    }
    mint ans = 1;
    for(ll i = 0; i < 60; i++) {
        mint count = 0;
        for (ll tmp = 0; tmp < (1 << N); tmp++) {
            bitset<20> s(tmp);
            bool flag = true;
            for(ll j = 0; j < Q; j++) {
                if((s.test(x.at(j) - 1) or s.test(y.at(j) - 1) or s.test(z.at(j) - 1)) == vec.at(i).at(j)) {
                    continue;
                }
                flag = false;
                break;
            }
            if(flag) {
                count++;
            }
        }
        ans *= count;
    }
    cout << ans.val() << endl;
    return 0;
}