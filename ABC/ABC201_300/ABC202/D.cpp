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

ll comb(ll n, ll r) {
    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
    ll res = 1;
    for(ll i = 1; i <= r; i++) {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}

int main(){
    ll A, B, K;
    cin >> A >> B >> K;
    //ll c = comb(A + B, A);
    string ans = "";
    ll index = 0;
    ll a = A;
    ll b = B;
    for(ll i = 1; i <= A + B; i++) {
        ll c = comb(a + b - 1, a - 1);
        if(K > c + index) {
            ans += 'b';
            b--;
            index += c;
        } else {
            ans += 'a';
            a--;
        }
    }

    cout << ans << endl;
    return 0;
}