#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> B(N - 1);
    for(ll i = 0; i < N - 1; i++) {
        cin >> B.at(i);
    }

    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        if(i == 0) {
            ans += B.at(i);
        } else if(i == N - 1) {
            ans += B.at(i - 1);
        } else {
            ans += min(B.at(i - 1), B.at(i));
        }
    }

    cout << ans << endl;
}