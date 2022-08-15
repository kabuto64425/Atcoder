#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N + 1);
    vector<ll> B(N);

    for(ll i = 0; i < N + 1; i++) {
        cin >> A.at(i);
    }

    for(ll i = 0; i < N; i++) {
        cin >> B.at(i);
    }

    ll ans = 0;

    for(ll i = 0; i < N; i++) {
        if(B.at(i) >= A.at(i)) {
            ans += A.at(i);
            B.at(i) -= A.at(i);
            A.at(i) = 0;
        } else {
            ans += B.at(i);
            A.at(i) -= B.at(i);
            B.at(i) = 0;
        }

        if(B.at(i) >= A.at(i + 1)) {
            ans += A.at(i + 1);
            B.at(i) -= A.at(i + 1);
            A.at(i + 1) = 0;
        } else {
            ans += B.at(i);
            A.at(i + 1) -= B.at(i);
            B.at(i) = 0;
        }
    }

    cout << ans << endl;
}