#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll recur(ll x, vector<ll> &memo) {
    if(x == 0) {
        return 1;
    }
    if(x == 1) {
        return 0;
    }
    if(x == 2) {
        return 0;
    }

    if(memo[x- 1] != -1) {
        return memo[x - 1];
    }

    return memo[x - 1] = (recur(x - 1, memo) + recur(x - 3, memo)) % mod;
}

int main() {
    //入力
    ll S;
    cin >> S;

    vector<ll> memo(S, -1);
    cout << recur(S, memo) << endl;
}