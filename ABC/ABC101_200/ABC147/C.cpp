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
    vector<ll> A(N);
    vector<vector<pair<ll, ll>>> xy(N);
    for(ll i = 0; i <N ;i++) {
        cin >> A.at(i);
        for(ll j = 0; j < A.at(i); j++) {
            ll x, y;
            cin >> x >> y;
            xy.at(i).push_back({x, y});
        }
    }
    ll ans = 0;
    for (ll bit = 0; bit < (1 << N); bit++) {
        bitset<20> s(bit);
        bool valid = true;
        for(ll i = 0; i < N; i++) {
            if(s.test(i)) {
                for(ll j = 0; j < A.at(i); j++) {
                    if(s.test(xy.at(i).at(j).first - 1) != xy.at(i).at(j).second) {
                        valid = false;
                    }
                }
            }
        }
        if(valid) {
            ans = max(ans, (ll)s.count());
        }
    }
    cout << ans << endl;
    return 0;
}