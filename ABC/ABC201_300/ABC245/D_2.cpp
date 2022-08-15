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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N + 1), C(N + M + 1);
    for(ll i = 0; i < N + 1; i++) {
        cin >> A.at(i);
    }
    for(ll i = 0; i < N + M + 1; i++) {
        cin >> C.at(i);
    }
    reverse(ALL(A));
    reverse(ALL(C));
    vector<ll> B(M + 1);
    for(ll i = 0; i < M + 1; i++) {
        ll b = C.at(i) / A.at(0);
        B.at(i) = b;
        for(ll j = 0; j < N + 1; j++) {
            C.at(i + j) -= A.at(j) * b;
        }
    }
    reverse(ALL(B));
    for(ll i = 0; i < M + 1; i++) {
        cout << B.at(i) << " ";
    }
    cout << endl;
    return 0;
}