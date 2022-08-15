#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll limit = 1000000000000000000;

int main() {
    //入力
    ll N;
    cin >> N;
    vector<ll> vec(N);
    for (ll i = 0; i < N; i++) {
      cin >> vec.at(i);
    }

    sort(vec.begin(), vec.end());

    ll ans = 1;
    for(ll i = 0; i < N; i++) {
        if(vec.at(i) <= limit / ans) {
            ans *= vec.at(i);
        } else {
            ans = -1;
            break;
        }
        if(ans == 0) {
            break;
        }
    }

    cout << ans << endl;
}