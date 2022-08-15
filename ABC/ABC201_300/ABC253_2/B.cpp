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

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(ll i = 0 ; i < H; i++) {
        cin >> S.at(i);
    }
    vector<pair<ll, ll>> pos;
    for(ll i = 0; i < H; i++) for(ll j = 0; j < W; j++) {
        if(S.at(i).at(j) == 'o') {
            pos.push_back({i, j});
        }
    }
    ll ans = abs(pos.at(0).first - pos.at(1).first) + abs(pos.at(0).second - pos.at(1).second);
    cout << ans << endl;
    return 0;
}