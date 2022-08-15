#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> p(N);
    for(ll i = 0; i < N; i++) {
        cin >> p.at(i);
    }

    vector<long double> sum(N);
    sum.at(0) = (p.at(0) + 1) / 2.0;
    for(ll i = 1; i < N; i++) {
        sum.at(i) = sum.at(i - 1) + (p.at(i) + 1) / 2.0;
    }

    long double ans = 0;
    for(ll i = K - 1; i < N; i++) {
        if(i == K - 1) {
            ans = max(ans, sum.at(i));
        } else {
            ans = max(ans, sum.at(i) - sum.at(i - K));
        }
    }

    cout << fixed << setprecision(20) << ans << endl;
}