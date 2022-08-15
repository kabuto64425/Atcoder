#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll T;
    cin >> T;
    vector<vector<ll>> squares(T);

    for(ll i = 0; i < T; i++) {
        vector<ll> square(3);
        cin >> square.at(0);
        cin >> square.at(1);
        cin >> square.at(2);
        squares.at(i) = square;
    }

    for(ll i = 0; i < T; i++) {
        ll N = squares.at(i).at(0);
        ll A = squares.at(i).at(1);
        ll B = squares.at(i).at(2);

        (N - B + 1) * (N - B + 1);
        cout << (N - A + 1) * (N - A + 1) << endl;
    }
}