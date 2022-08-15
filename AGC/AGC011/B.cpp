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
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    sort(ALL(A));
    vector<ll> csum(N + 1);
    for(ll i = 1; i <= N; i++) {
        csum.at(i) = csum.at(i - 1) + A.at(i - 1);
    }
    ll ans = 0;
    for(ll i = 1; i <= N - 1; i++) {
        if(csum.at(i) * 2 >= A.at(i)) {
            ans++;
        } else {
            ans = 0;
        }
    }
    ans++;
    cout << ans << endl;
    return 0;
}