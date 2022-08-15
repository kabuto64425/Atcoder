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

    vector<ll> SUM(N);
    SUM.at(0) = A.at(0);
    for(ll i = 1; i < N; i++) {
        SUM.at(i) = SUM.at(i - 1) + A.at(i);
    }

    ll ans = SUM.at(N - 1);
    for(ll i = 0; i < N - 1; i++) {
        ans = min(ans, abs(SUM.at(N - 1) - SUM.at(i) * 2));
    }

    cout << ans << endl;
}