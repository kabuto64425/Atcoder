#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> vec(N);

    for(ll i = 0; i < N; i++) {
        cin >> vec.at(i);
    }

    sort(vec.begin(), vec.end());

    long double ans = vec.at(0);
    for(ll i = 1; i < N; i++) {
        ans = (ans + vec.at(i)) / 2;
    }

    cout << fixed << setprecision(20) << ans << endl;
}