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

    ll ans = 0;
    ll count = 0;

    for(ll i = 0; i < N - 1; i++) {
        vec.at(i);
        vec.at(i + 1);
        if(vec.at(i) >= vec.at(i + 1)) {
            count++;
            ans = max(ans, count);
        } else {
            ans = max(ans, count);
            count = 0;
        }
    }

    cout << ans << endl;
}