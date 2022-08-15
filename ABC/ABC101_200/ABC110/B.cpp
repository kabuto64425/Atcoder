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
    ll N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    vector<ll> B(M);
    for(ll &b : B) {
        cin >> b;
    }
    ll x_max = max(*max_element(A.begin(), A.end()), X);
    ll y_min = min(*min_element(B.begin(), B.end()), Y);
    if(y_min <= x_max) {
        cout << "War" << endl;
        return 0;
    }
    cout << "No War" << endl;
    return 0;
}