#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(ll i = 0; i < N; i++) {
        cin >> a.at(i);
    }

    ll index = 1;
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        if(a.at(i) == index) {
            index++;
        } else {
            ans++;
        }
    }
    if(ans == N) {
        ans = -1;
    }
    cout << ans << endl;
}