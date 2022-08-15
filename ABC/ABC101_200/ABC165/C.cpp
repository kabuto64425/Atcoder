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

void recursive_h(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    // sを使わないパターン
    recursive_h(indexes, s - 1, rest, f);
    // sを使うパターン
    indexes[rest - 1] = s;
    recursive_h(indexes, s, rest - 1, f);
  }
}

// nHkの組み合わせに対して処理を実行する
void foreach_h(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_h(indexes, n - 1, k, f);
}

int main(){
    ll N, M , Q;
    cin >> N >> M >> Q;
    vector<tuple<ll, ll, ll, ll>> abcd(Q);
    for(tuple<ll, ll, ll, ll> &elm : abcd) {
        cin >> get<0>(elm) >> get<1>(elm) >> get<2>(elm) >> get<3>(elm);
    }
    ll ans = 0;
    foreach_h(M, N, [&ans, &abcd](int *indexes) {
        ll current = 0;
        for(const tuple<ll, ll, ll, ll> &elm : abcd) {
            if(indexes[get<1>(elm) - 1] - indexes[get<0>(elm) - 1] == get<2>(elm)) {
                current += get<3>(elm);
            }
        }
        ans = max(ans, current);
    });
    cout << ans << endl;
    return 0;
}