#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    ll K, N;
    cin >> K >> N;
    vector<ll> vec(N);
    for(ll i = 0; i < N; i++) {
        cin >> vec.at(i);
    }

    ll currentMax = 0;

    for(ll i = 0; i < N; i++) {
        ll current = 0;
        if(i == N - 1) {
            current = K - vec.at(i) + vec.at(0);
        } else {
            current = vec.at(i + 1) - vec.at(i);
        }
        currentMax = max(currentMax, current);
    }

    cout << (K - currentMax) << endl;
}