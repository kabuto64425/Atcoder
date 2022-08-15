#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    sort(A.begin(), A.end());

    ll ans = 1;
    for(ll i = 0; i < N; i++) {
        if(A.at(i) != 0 && (ans > 1e18 / A.at(i))) {
            ans = -1;
            break;
        }
        ans *= A.at(i);
    }

    if(ans > 1000000000000000000) {
        ans = -1;
    }

    cout << ans << endl;
}