#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    
    ll ans = 0;
    for(ll b = 1; b <= N; b++) {
        if(b <= K) {
            continue;
        }
        ll div = N / b;
        ll mod = N % b;
        if(mod >= K) {
            ans += div * (b - K) + (mod - K) ;
            if(K > 0) {
                ans++;
            }
        } else {
            ans += div * (b - K);
        }
    }

    cout << ans << endl;
}