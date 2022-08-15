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
    ll N, M;
    cin >> N >> M;
    vector<bool> likes(M, true);
    REP(i, N) {
        ll K;
        cin >> K;
        vector<bool> vec(M);
        REP(j, K) {
            ll x;
            cin >> x;
            vec.at(x - 1) = true;
        }
        REP(j, M) {
            if(!vec.at(j)) {
                likes.at(j) = false;
            }
        }
    }
    cout << count(likes.begin(), likes.end(), true) << endl;
    return 0;
}