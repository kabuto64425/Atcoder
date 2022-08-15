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
    ll N, M;
    cin >> N >> M;
    if(M == 0) {
        cout << 1 << endl;
        return 0;
    }
    vector<ll> A(M);
    for(ll &a: A) {
        cin >> a;
    }
    sort(A.begin(), A.end());
    vector<ll> span(M + 1);
    for(ll i = 0; i < M; i++) {
        if(i == 0) {
            span.at(i) = A.at(i) - 1;
        } else {
            span.at(i) = A.at(i) - A.at(i - 1) - 1;
        }
    }
    span.at(M) = N - A.at(M - 1);
    ll spanmin = INF;
    for(ll i = 0; i < M + 1; i++) {
        if(span.at(i) == 0) {
            continue;
        }
        spanmin = min(spanmin, span.at(i));
    }
    ll ans = 0;
    for(ll i = 0; i < M + 1; i++) {
        if(span.at(i) == 0) {
            continue;
        }
        ans += (span.at(i) + (spanmin - 1)) / spanmin;
    }
    cout << ans << endl;
    return 0;
}