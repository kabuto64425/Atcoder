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
    ll N, K;
    cin >> N >> K;
    vector<ll> p(N);
    for(ll &elm : p) {
        cin >> elm;
    }
    vector<ll> sum(N + 1, 0);
    for(ll i = 0; i < N; i++) {
        sum.at(i + 1) = sum.at(i) + p.at(i);
    }
    ll index = INF;
    ll max = 0;
    for(ll i = K; i <= N; i++) {
        if(max < sum.at(i) - sum.at(i - K)) {
            index = i - 1;
            max = sum.at(i) - sum.at(i - K);
        }
    }
    long double ans = 0;
    for(ll i = 0; i < K; i++) {
        ans += (p.at(index - i) + 1) / (long double) 2.0;
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}