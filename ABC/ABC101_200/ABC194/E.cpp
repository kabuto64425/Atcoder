#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    vector<ll> bucket(N + 1, 0);
    for(ll i = 0; i < M; i++) {
        bucket.at(A.at(i))++;
    }
    ll ans = INF;
    for(ll i = 0; i < N + 1; i++) {
        if(bucket.at(i) == 0) {
            ans = i;
            break;
        }
    }
    for(ll i = 1; i <= N - M ; i++) {
        bucket.at(A.at(i - 1))--;
        bucket.at(A.at(i + M - 1))++;
        if(bucket.at(A.at(i - 1)) == 0 and ans > A.at(i - 1)) {
            ans = A.at(i - 1);
        }
    }
    cout << ans << endl;
    return 0;
}