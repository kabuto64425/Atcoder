#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll A, ll B, ll x) {
    return (ll)(floor(A * x / B) - A * floor(x / B));
}

int main() {
    ll A, B, N;
    cin >> A >> B >> N;

    if(B - 1 >= N) {
        cout << f(A, B, N) << endl;
    } else {
        cout << f(A, B, B - 1) << endl;
    }
}