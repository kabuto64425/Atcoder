#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<ll>> LR(N + 1, vector<ll>(N + 1, 0));
    REP(i, M) {
        ll l, r;
        cin >> l >> r;
        LR[r][l]++;
    }
    vector<pair<ll, ll>> pq(Q);
    for(auto &elm : pq) {
        cin >> elm.first >> elm.second;
    }
    vector<vector<ll>> sum = LR;
    for(ll i = 1; i <= N; i++) {
        for(ll j = 1; j <= N; j++) {
            sum[i][j] += sum[i][j - 1];
        }
    }
    for(ll i = 1; i <= N; i++) {
        for(ll j = 1; j <= N; j++) {
            sum[j][i] += sum[j - 1][i];
        }
    }

    for(const auto &elm : pq) {
        cout << sum[elm.second][elm.second] - sum[elm.first - 1][elm.second] - sum[elm.second][elm.first - 1] + sum[elm.first - 1][elm.first - 1] << endl;
    }

    return 0;
}