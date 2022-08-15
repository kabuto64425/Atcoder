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
    set<ll> s;
    for(ll i = 1; i * i <= N; i++) {
        if(i == 1) {
            continue;
        }
        ll a = i;
        while(a * i <= N) {
            a *= i;
            s.insert(a);
        }
    }
    cout << N - s.size() << endl;
    return 0;
}