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

int main(){
    ll N, M;
    cin >> N >> M;
    ll C;
    cin >> C;
    vector<ll> B(M);
    for(ll &b : B) {
        cin >> b;
    }
    vector<vector<ll>> A(N, vector<ll>(M));
    for(vector<ll> &elm : A) {
        for(ll &a : elm) {
            cin >> a;
        }
    }
    ll ans = 0;
    for(const vector<ll> &elm : A) {
        ll res = 0;
        for(ll i = 0; i < M; i++) {
            res += elm.at(i) * B.at(i);
        }
        res += C;
        if(res > 0) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}