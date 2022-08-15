#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //入力
    ll N, D;
    cin >> N >> D;
    vector<pair<ll, ll>> vec(N);

    for(ll i = 0; i < N; i++) {
        cin >> vec.at(i).first >> vec.at(i).second;
    }

    //処理
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        ll length = vec.at(i).first * vec.at(i).first + vec.at(i).second * vec.at(i).second;
        if(length  <= D *D) {
            ans++;
        }
    }

    cout << ans << endl;
}