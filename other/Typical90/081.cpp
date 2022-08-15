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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i) >> B.at(i);
    }

    const ll M = 5000;

    vector<vector<ll>> csum(M + 1, vector<ll>(M + 1));
    for(ll i = 0; i < N; i++) {
        csum.at(A.at(i)).at(B.at(i))++;
    }
    for(ll i = 0; i <= M; i++) {
        for(ll j = 1; j <= M; j++) {
            csum.at(i).at(j) += csum.at(i).at(j - 1);
        }
    }
    for(ll j = 0; j <= M; j++) {
        for(ll i = 1; i <= M; i++) {
            csum.at(i).at(j) += csum.at(i - 1).at(j);
        }
    }

    ll ans = 0;

    for(ll i = K; i <= M; i++) {
        for(ll j = K; j <= M; j++) {
            ll count = 0;
            count = csum.at(i).at(j);
            if(i - K - 1 >= 0) {
                count -=  csum.at(i - K - 1).at(j);
            }
            if(j - K - 1 >= 0) {
                count -=  csum.at(i).at(j - K - 1);
            }
            if(i - K - 1 >= 0 and j - K - 1 >= 0) {
                count += csum.at(i - K - 1).at(j - K - 1);
            }
            ans = max(ans, count);
        }
    }

    cout << ans << endl;
    return 0;
}