#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 998244353;

int main() {
    //入力
    ll N, K;
    cin >> N >> K;
    vector<vector<ll>> kukan(K);
    for (ll i = 0; i < K; i++) {
      vector<ll> lr(2);
      cin >> lr.at(0) >> lr.at(1);
      kukan.at(i) = lr;
    }

    //処理

    vector<ll> masu(N, 0);
    masu.at(0) = 1;

    vector<ll> sumMasu(N, 0);
    sumMasu.at(0) = 1;

    for(ll i = 1; i < N; i++) {
      ll current = 0;
      for(ll j = 0; j < K; j++) {
        ll l = kukan.at(j).at(0);
        ll r = kukan.at(j).at(1);
        if(i - l >= 0) {
          current += sumMasu.at(i - l);
          current %= mod;
        }
        if(i - r - 1 >= 0) {
          current -= sumMasu.at(i - r - 1);
          current = (current + mod) % mod;
        }
      }
      masu.at(i) = current;
      sumMasu.at(i) = (sumMasu.at(i - 1) + masu.at(i)) % mod;
    }

    cout << masu.at(N - 1) << endl;
}