#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //入力
    ll N;
    cin >> N;
    vector<ll> x(N);

    for(ll i = 0; i < N; i++) {
        cin >> x.at(i);
    }

    ll ans1 = 0;
    long double ans2 = 0;
    ll ans3 = 0;

    for(ll i = 0; i < N; i++) {
        ans1 += abs(x.at(i));
        ans2 += x.at(i) * x.at(i);
        ans3 = max(ans3, abs(x.at(i)));
    }

    ans2 = sqrt(ans2);

    cout << ans1 << endl;
    cout << fixed << setprecision(20) << ans2 << endl;
    cout << ans3 << endl;
}