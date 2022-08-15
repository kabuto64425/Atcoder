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


int main(){
    COMinit();
    ll N, M;
    cin >> N >> M;
    if(abs(N - M) >= 2) {
        cout << 0 << endl;
        return 0;
    }
    if(N == M) {
        mint ans = fac[N] * fac[M] * 2;
        cout << ans.val() << endl;
        return 0;
    }
    ll l = max(N, M);
    ll s = min(N, M);
    mint ans = fac[l] * fac[s];
    cout << ans.val() << endl;
    return 0;
}