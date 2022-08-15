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
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll sum = 0;
    for(ll &a : A) {
        cin >> a;
        sum += a;
    }
    vector<ll> odd(N + 1, 0);
    vector<ll> even(N + 1, 0);
    for(ll i = 1; i <= N; i++) {
        if(i % 2 == 1) {
            odd.at(i) = odd.at(max(i - 2, 0LL)) + A.at(i - 1);
        } else {
            even.at(i) = even.at(max(i - 2, 0LL)) + A.at(i - 1);
        }
    }
    for(ll i = 1; i <= N; i++) {
        if(i % 2 == 1) {
            ll ans = sum;
            ans -= (even.at(N - 1) - even.at(i - 1)) * 2;
            ans -= (odd.at(max(i - 2, 0LL)) - odd.at(0)) * 2;
            cout << ans << " ";
        } else {
            ll ans = sum;
            ans -= (odd.at(N) - odd.at(i - 1)) * 2;
            ans -= (even.at(max(i - 2, 0LL)) - even.at(0)) * 2;
            cout << ans << " ";
        }
    }
    cout << endl;
    return 0;
}