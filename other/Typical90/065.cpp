#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 998244353;

const int MAX = 1100000;

mint fac[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i;
    }
}

// 二項係数計算
mint COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] / (fac[k] * fac[n - k]);
}

void dfs(const ll R, const ll G, const ll B, const ll X, const ll Y, const ll Z, ll rest, ll size, vector<ll> &vec, mint &ans) {
    if((ll)vec.size() == (size - 1)) {
        ll r = vec.at(0);
        ll g = vec.at(1);
        ll b = rest;
        if(r > R) {
            return;
        }
        if(g > G) {
            return;
        }
        if(b > B) {
            return;
        }
        if(r + g > X or g + b > Y or b + r > Z) {
            return;
        }
        mint current = 1;
        current *= COM(R, r);
        current *= COM(G, g);
        current *= COM(B, b);
        ans += current;
        return;
    }
    for(ll i = rest; i >= 0; i--) {
        vec.push_back(i);
        dfs(R, G, B, X, Y, Z, rest - i, size, vec, ans);
        vec.pop_back();
    }
}

int main(){
    ll R, G, B, K;
    cin >> R >> G >> B >> K;
    ll X, Y, Z;
    cin >> X >> Y >> Z;
    vector<ll> vec;
    mint ans = 0;
    COMinit();
    dfs(R, G, B, X, Y, Z, K, 3, vec, ans);
    cout << ans.val() << endl;
    return 0;
}