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
    vector<ll> B(N);
    for(ll i = 0; i < N; i++) {
        B.at(i) = A.at(i) - (i + 1);
    }
    sort(ALL(B));
    if(N % 2 == 1) {
        ll b = B.at(N / 2);
        ll ans = 0;
        for(ll i = 0; i < N; i++) {
            ans += abs(B.at(i) - b);
        }
        cout << ans << endl;
    } else {
        ll b = (B.at(N / 2) + B.at((N / 2) - 1)) / 2;
        ll ans = 0;
        for(ll i = 0; i < N; i++) {
            ans += abs(B.at(i) - b);
        }
        cout << ans << endl;
    }
    return 0;
}