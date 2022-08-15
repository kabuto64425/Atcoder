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
    ll split = N / 2;
    cout << vec.at(split) - vec.at(split - 1) << endl;
}