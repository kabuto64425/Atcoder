#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    //入力
    ll N;
    cin >> N;
    vector<ll> vec(N);
    for (ll i = 0; i < N; i++) {
      cin >> vec.at(i);
    }

    //処理

    ll x = 0;
    ll sum = 0;

    for(ll i = 1; i < N; i++) {
        ll y = vec.at(i - 1) + x;
        if(vec.at(i) < y) {
            x = y - vec.at(i);
        } else {
            x = 0;
        }
        sum += x;
    }

    cout << sum << endl;
}