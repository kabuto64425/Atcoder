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
    ll N, K, M;
    cin >> N >> K >> M;
    vector<ll> A(N - 1);
    for(ll &a : A) {
        cin >> a;
    }
    ll sum = accumulate(A.begin(), A.end(), 0LL);
    ll rest = N * M - sum;
    if(rest > K) {
        cout << -1 << endl;
        return 0;
    }
    cout << max(rest, 0LL) << endl;
    return 0;
}