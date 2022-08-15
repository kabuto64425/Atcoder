#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    ll K;
    cin >> K;
    ll ans = 0;
    for(ll a = 1; a <= K; a++) {
        for(ll b = 1; b <= K; b++) {
            for(ll c = 1; c <= K; c++) {
                ans += gcd(gcd(a,b), c);
            }
        }
    }
    cout << ans << endl;
}