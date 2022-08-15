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

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    sort(A.begin(), A.end());
    vector<ll> csum(N + 1);
    for(ll i = 1; i <= N; i++) {
        csum.at(i) = csum.at(i - 1) + A.at(i- 1);
    }
    ll sum = csum.at(N);
    ll ans = INF;
    for(ll i = 0; i <= N; i++) {
        if(i == 0) {
            ans = min(ans, sum * 2);
            continue;
        }
        ans = min(ans, (A.at(i - 1) * N) + (sum - csum.at(i) - A.at(i - 1) * (N - i)) * 2);
    }
    cout << fixed << setprecision(20) << ans / (long double)(N * 2) << endl;
    return 0;
}