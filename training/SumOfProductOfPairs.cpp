#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long mod=1000000007;

int main() {
    //入力
    ll N;
    cin >> N;
    vector<ll> vec(N);
    for (ll i = 0; i < N; i++) {
      cin >> vec.at(i);
    }

    //処理
    ll ans = 0;

    vector<ll> vec2(N);
    for(ll i = 1; i <= N; i++) {
      if(i == 1) {
        vec2.at(i - 1) = vec.at(i - 1) % mod;
      } else {
        vec2.at(i - 1) = (vec2.at(i - 2) + vec.at(i - 1)) % mod;
      }
    }

    for(ll i = 1; i <= N - 1; i++) {
      ans += vec.at(i - 1) * (vec2.at(N - 1) - vec2.at(i - 1) + mod) % mod;
      ans = ans % mod;
    }

    cout << ans << endl;
}