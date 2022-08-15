#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll H;
    cin >> H;

    ll x = 1;
    while(x * 2 <= H) {
        x *= 2;
    }

    cout << x * 2 - 1 << endl;
}