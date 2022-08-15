#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> p(N);

    for(ll i = 0; i < N; i++) {
        cin >> p.at(i);
    }

    ll current = 0;
    vector<bool> flags(200001, false);
    for(ll i = 0; i < N; i++) {
        flags.at(p.at(i)) = true;
        for(ll j = current; j < flags.size(); j++) {
            if(!flags.at(j)) {
                current = j;
                break;
            }
        }
        cout << current <<endl;
    }
}