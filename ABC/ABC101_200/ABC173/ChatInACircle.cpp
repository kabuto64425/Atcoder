#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //入力
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    sort(A.begin(), A.end(), greater<ll>());

    ll ans = 0;
    for(ll i = 1; i <= N - 1; i++) {
        ans += A.at(i / 2);
    }

    cout << ans << endl;
}