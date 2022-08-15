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

    bool flag = true;
    for(ll i = 0; i < N - 1; i++) {
        if(vec.at(i) == vec.at(i + 1)) {
            flag = false;
            break;
        }
    }

    if(flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}