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
    vector<ll> A(4 * N - 1);
    for(ll &a : A) {
        cin >> a;
    }
    vector<ll> bucket(N);
    for(ll &a : A) {
        bucket.at(a - 1)++;
    }
    for(ll i = 0; i < N; i++) {
        if(bucket.at(i) <= 3) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}