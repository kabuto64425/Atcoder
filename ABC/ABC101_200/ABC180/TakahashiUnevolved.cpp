#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //入力
    ll X, Y, A, B;
    cin >> X >> Y >> A >> B;

    ll ans = 0;
    while((X <= 1000000000000000000 / A) && (X * A < Y) && (X * A < X + B)) {
        X *= A;
        ans++;
    }

    Y = Y - X - 1;
    cout << ans + Y / B << endl;
}