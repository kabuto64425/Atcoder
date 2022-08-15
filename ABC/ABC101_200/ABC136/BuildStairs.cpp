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

    bool flag = true;
    for(ll i = N - 1; i >= 1; i--) {
        if(vec.at(i - 1) - vec.at(i) == 1) {
            vec.at(i - 1) -= 1;
        } else if(vec.at(i - 1) - vec.at(i) >= 2) {
            flag = false;
        }
    }

    if(flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}