#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //入力
    ll K;
    cin >> K;

    //処理
    ll ans = -1;
    ll x = 0;
    for(ll i = 1; i <= K; i++) {
      x = (x * 10 + 7) % K;
      if(x == 0) {
        ans = i;
        break;
      }
    }
    cout << ans << endl;
}