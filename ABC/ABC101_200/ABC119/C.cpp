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

void recur(ll A, ll B, ll C, bool usedA, bool usedB, bool usedC, ll &ans, ll cost, const vector<ll> l, ll n, const ll N) {
    if(n == N) {
        if(usedA && usedB && usedC) {
            ans = min(ans, cost + abs(A) + abs(B) + abs(C));
        }
        return;
    }
    recur(A - l.at(n), B, C, usedA | true, usedB, usedC, ans, ((usedA)? cost + 10 : cost), l, n + 1, N);
    recur(A, B - l.at(n), C, usedA, usedB | true, usedC, ans, ((usedB)? cost + 10 : cost), l, n + 1, N);
    recur(A, B, C - l.at(n), usedA, usedB, usedC | true, ans, ((usedC)? cost + 10 : cost), l, n + 1, N);
    recur(A, B, C, usedA, usedB, usedC, ans, cost, l, n + 1, N);
}

int main(){
   ll N;
    cin >> N;
    ll A, B, C;
    cin >> A >> B >> C;
    vector<ll> l(N);
    for(ll &elm : l) {
        cin >> elm;
    }
    ll ans = INF;
    recur(A, B, C, false, false, false, ans, 0, l, 0, N);
    cout << ans << endl;
    return 0;
}