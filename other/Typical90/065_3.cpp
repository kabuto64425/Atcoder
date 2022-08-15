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

int main(){
    ll R, G, B, K;
    cin >> R >> G >> B >> K;
    ll X, Y, Z;
    cin >> X >> Y >> Z;
    vector<ll> vec;
    mint ans = 0;
    COMinit();
    ll lR = K - Y;
    ll lG = K - Z;
    ll lB = K - X;

    vector<mint> ar(220000),  ag(220000),  ab(220000);
    for(ll i = 0; i <= R; i++) {
        ar.at(i) = COM(R, i);
    }
    for(ll i = 0; i <= G; i++) {
        ag.at(i) = COM(G, i);
    }
    for(ll i = 0; i <= B; i++) {
        ab.at(i) = COM(B, i);
    }

    // 畳み込み
    vector<mint> p1(R + 1, 0), p2(G + 1, 0), p3;
    for (int i = lR; i <= R; i++) {
        p1.at(i) = ar.at(i);
    }
    for (int i = lG; i <= G; i++) {
        p2.at(i) = ag.at(i);
    }
    p3 = convolution(p1, p2);

    for(ll i = 0; i <= K; i++) {
        ll k = K - i;
        if(k < lB) {
            continue;
        }
        if(k > B) {
            continue;
        }
        ans += p3.at(i) * COM(B, k);
    }

    cout << ans.val() << endl;
    return 0;
}