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

    ll max = A.at(N - 1);

    vector<ll> vec(max + 1, 0);

    for(ll i = 0; i < N; i++) {
        ll x = A.at(i);
        for(ll j = 1; j * x <= max; j++) {
            vec.at(j * x) += 1;
        }
    }

    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        ll x = A.at(i);
        if(vec.at(x) == 1) {
            ans++;
        }
    }

    cout << ans << endl;
}