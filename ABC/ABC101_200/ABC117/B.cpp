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
    vector<ll> L(N);
    for(ll &l : L) {
        cin >> l;
    }
    sort(L.begin(), L.end());
    ll sum = 0;
    for(ll i = 0; i < N - 1; i++) {
        sum += L.at(i);
    }
    cout << ((sum > L.at(N - 1))? "Yes" : "No") << endl;
    return 0;
}