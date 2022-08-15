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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    ll shift = 0;
    REP(repeat, Q) {
        ll T, x, y;
        cin >> T >> x >> y;
        if(T == 1) {
            swap(A.at((x - 1 - shift + N) % N), A.at((y - 1 - shift + N) % N));
        } else if(T == 2) {
            shift = (shift + 1) % N;
        } else if(T == 3) {
            cout << A.at((x - 1 - shift + N) % N) << endl;
        }
    }
    return 0;
}