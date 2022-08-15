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
    ll H, W, A, B;
    cin >> H >> W >> A >> B;
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if((j < A and i < B) or (j >= A and i >= B)) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout << endl;
    }
    return 0;
}