#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll Q, S, H, D;
    cin >> Q >> S >> H >> D;
    ll N;
    cin >> N;
    N *= 4;

    vector<ll> vec(1000, INF);
    vec.at(0) = 0;
    for(ll i = 0; i <= 8; i++) {
        vec.at(i + 1) = min(vec.at(i + 1), vec.at(i) + Q);
        vec.at(i + 2) = min(vec.at(i + 2), vec.at(i) + S);
        vec.at(i + 4) = min(vec.at(i + 4), vec.at(i) + H);
        vec.at(i + 8) = min(vec.at(i + 8), vec.at(i) + D);
    }
    ll ans = 0;
    ans += (N / 8) * vec.at(8);
    N = N % 8;
    ans += (N / 4) * vec.at(4);
    N = N % 4;
    ans += (N / 2) * vec.at(2);
    N = N % 2;
    ans += N * vec.at(2);
    cout << ans << endl;
    return 0;
}