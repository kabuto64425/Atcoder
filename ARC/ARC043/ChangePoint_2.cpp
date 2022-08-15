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
    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> S(N);
    for(ll &s : S) {
        cin >> s;
    }

    ll ma = *max_element(S.begin(), S.end());
    ll mi = *min_element(S.begin(), S.end());
    if(ma == mi) {
        cout << -1 << endl;
        return 0;
    }
    long double P = B / (long double)(ma - mi);
    long double Q = A - P * accumulate(S.begin(), S.end(), 0LL) / N;
    cout << fixed << setprecision(20) << P << " " << Q << endl;

    return 0;
}