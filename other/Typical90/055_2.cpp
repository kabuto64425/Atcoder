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

ll N, P, Q;
vector<ll> A(1000);
ll ans = 0;

void recursive_comb(int *indexes, int s, int rest) {
  if (rest == 0) {
    ll current = 1;
    current *= A.at(indexes[0]);
    current %= P;
    current *= A.at(indexes[1]);
    current %= P;
    current *= A.at(indexes[2]);
    current %= P;
    current *= A.at(indexes[3]);
    current %= P;
    current *= A.at(indexes[4]);
    current %= P;
    if(current == Q) {
        ans++;
    }
  } else {
    // 見込みなしと判断
    if (s + 1 < rest) return;
    // sを使わないパターン
    recursive_comb(indexes, s - 1, rest);
    // sを使うパターン
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k);
}

int main(){
    cin >> N >> P >> Q;
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    foreach_comb(N, 5);
    cout << ans << endl;
    return 0;
}