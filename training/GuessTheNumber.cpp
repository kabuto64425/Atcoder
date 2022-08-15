#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;

    vector<vector<ll>> vec(M, vector<ll>(2));
    for (ll i = 0; i < M; i++) {
      cin >> vec.at(i).at(0) >> vec.at(i).at(1);
    }

    vector<ll> number(N, -1);
    bool minusFlag = false;
    for (ll i = 0; i < M; i++) {
      if(number.at(vec.at(i).at(0) - 1) != -1 && number.at(vec.at(i).at(0) - 1) != vec.at(i).at(1)) {
        minusFlag = true;
        break;
      }
      number.at(vec.at(i).at(0) - 1) = vec.at(i).at(1);
    }

    if(N > 1 && number.at(0) == 0) {
      minusFlag = true;
    }
    
    if(minusFlag) {
      cout << -1 << endl;
      return 0;
    }

    ll ans = 0;
    for(ll i = 0; i < N; i++) {
      ll temp = 0;
      if(number.at(i) == -1) {
        if(N > 1 && i == 0) {
          temp = 1;
        } else {
          temp = 0;
        }
      } else {
        temp = number.at(i);
      }
      ans = ans * 10 + temp;
    }

    cout << ans << endl;
}