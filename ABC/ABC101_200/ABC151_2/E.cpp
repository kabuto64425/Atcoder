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

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

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
    if(n == 0 and k == 0) {
        return 0;
    }
    return fac[n] / (fac[k] * fac[n - k]);
}

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    COMinit();
    vector<mint> csum(MAX);
    for(ll i = 0; i < MAX; i++) {
        csum.at(i) = COM(i, K - 2);
    }
    for(ll i = 1; i < MAX; i++) {
        csum.at(i) += csum.at(i - 1);
    }

    sort(ALL(A));
    mint ans = 0;
    if(K == 2) {
        for(ll i = 0; i < N; i++) {
            mint current = A.at(i);
            current *= N - 1 - i;
            current *= -1;
            ans += current;
        }
        reverse(ALL(A));
        for(ll i = 0; i < N; i++) {
            mint current = A.at(i);
            current *= N - 1 - i;
            ans += current;
        }
        cout << ans.val() << endl;
        return 0;
    }

    for(ll i = 0; i < N; i++) {
        /*if(N - K + 1 - i <= 0) {
            continue;
        }*/
        ll minus = max(N - 2 - i, 0LL);
        mint current = A.at(i);
        current *= csum.at(minus);
        ans -= current;
    }
    reverse(ALL(A));
    for(ll i = 0; i < N; i++) {
        /*if(N - K + 1 - i <= 0) {
            continue;
        }*/
        ll plus = max(N - 2 - i, 0LL);
        mint current = A.at(i);
        current *= csum.at(plus);
        ans += current;
    }
    cout << ans.val() << endl;
    return 0;
}