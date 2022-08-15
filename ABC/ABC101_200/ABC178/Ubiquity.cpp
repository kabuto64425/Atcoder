#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll powmod(ll x, ll y) {
    ll ret = 1;
    for(ll i = 0; i < y; i++) {
        ret = ret * x % mod;
    }
    return ret;
}

int main() {
    //入力
    ll N;
    cin >> N;
    ll ans = (powmod(10, N) - powmod(9, N) - powmod(9, N) + powmod(8, N)) % mod;
    ans = (ans + mod) % mod;
    cout << ans << endl;
}