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
    string S;
    cin >> S;
    if(N % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }
    ll offset = (4 - ((N - 1) / 2) % 3) % 3;
    bool flag = true;
    for(ll j = 0; j < N; j++) {
        ll x = (ll)(S.at(j) - 'a');
        ll y = (ll)(offset + j) % 3;
        if(x != y) {
            flag = false;
        }
    }
    if(flag) {
        cout << (N - 1) / 2 << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}