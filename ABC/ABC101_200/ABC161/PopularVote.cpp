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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    ll total = 0;
    for(ll &a : A) {
        cin >> a;
        total += a;
    }
    ll select = 0;
    for(const ll &a : A) {
        if(4 * M * a >= total) {
            select++;
        }
    }
    if(select >= M) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}