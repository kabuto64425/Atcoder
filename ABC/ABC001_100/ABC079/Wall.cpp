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
    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> c(10, vector<ll>(10));
    for(vector<ll> &vec : c) {
        for(ll &elm : vec) {
            cin >> elm;
        }
    }
    vector<vector<ll>> A(H, vector<ll>(W));
    for(vector<ll> &vec : A) {
        for(ll &elm : vec) {
            cin >> elm;
        }
    }
    
    for (int k = 0; k < 10; k++){       // 経由する頂点
        for (int i = 0; i < 10; i++) {    // 始点
            for (int j = 0; j < 10; j++) {  // 終点
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }
    ll ans = 0;
    for(const vector<ll> &vec : A) {
        for(const ll &elm : vec) {
            if(elm == -1) {
                continue;
            }
            ans += c[elm][1];
        }
    }
    cout << ans << endl;
    return 0;
}