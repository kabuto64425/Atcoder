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

    ll ans = 1;
    vector<ll> mins(N);
    mins.at(0) = vec.at(0);
    for(ll i = 1; i < N; i++) {
        if(vec.at(i) <= mins.at(i - 1)) {
            ans++;
        }
        mins.at(i) = min(mins.at(i - 1), vec.at(i));
    }
    cout << ans << endl;
}