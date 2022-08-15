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

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M), B(M), C(M);
    for(ll i = 0; i < M; i++) {
        cin >> A.at(i) >> B.at(i) >> C.at(i);
    }
    vector<vector<ll>> dist(N, vector<ll>(N, INF));
    // ワーシャルフロイド
    for(ll i = 0; i < M; i++) {
        dist[A.at(i) - 1][B.at(i) - 1] = C.at(i);
        dist[B.at(i) - 1][A.at(i) - 1] = C.at(i);
    }
    for (int i = 0; i < N; i++) {
        dist[i][i] = 0;
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
    
    ll ans = 0;
    for(ll i = 0; i < M; i++) {
        ll a = A.at(i) - 1;
        ll b = B.at(i) - 1;
        if(dist[a][b] != C.at(i)) {
            ans++;
            continue;
        }
        for(ll j = 0; j < N; j++) {
            if(a == j or b == j) {
                continue;
            }
            if(dist[a][j] + dist[j][b] == C.at(i)) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}