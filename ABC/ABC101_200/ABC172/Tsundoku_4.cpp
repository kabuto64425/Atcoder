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
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    vector<ll> B(M);
    for(ll &a : A) {
        cin >> a;
    }
    for(ll &b : B) {
        cin >> b;
    }
    vector<ll> sumA(N + 1, 0);
    vector<ll> sumB(M + 1, 0);
    for(ll i = 1; i <= N; i++) {
        sumA.at(i) = sumA.at(i - 1) + A.at(i - 1);
    }
    for(ll i = 1; i <= M; i++) {
        sumB.at(i) = sumB.at(i - 1) + B.at(i - 1);
    }
    ll ans = 0;
    for(ll i = 0; i <= N; i++) {
        if(sumA.at(i) > K) {
            break;
        }
        ll rest = K - sumA.at(i);
        ll index = upper_bound(sumB.begin(), sumB.end(), rest) - sumB.begin();
        ans = max(ans, i + index - 1);
    }

    cout << ans << endl;

    return 0;
}