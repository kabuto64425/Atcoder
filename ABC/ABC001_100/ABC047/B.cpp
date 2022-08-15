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
    ll W, H, N;
    cin >> W >> H >> N;
    vector<ll> x(N), y(N), a(N);
    for(ll i = 0; i < N; i++) {
        cin >> x.at(i) >> y.at(i) >> a.at(i);
    }
    ll left = 0;
    ll right = W;
    ll up = H;
    ll down = 0;
    for(ll i = 0; i < N; i++) {
        if(a.at(i) == 1) {
            left = max(left, x.at(i));
        }
        if(a.at(i) == 2) {
            right = min(right, x.at(i));
        }
        if(a.at(i) == 3) {
            down = max(down, y.at(i));
        }
        if(a.at(i) == 4) {
            up = min(up, y.at(i));
        }
    }
    cout << max(up - down, 0LL) * max(right - left, 0LL) << endl;
    return 0;
}