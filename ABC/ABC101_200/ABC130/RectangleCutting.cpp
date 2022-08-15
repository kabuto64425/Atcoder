#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll W, H, x, y;
    cin >> W >> H >> x >> y;

    ll another = 0;
    if(x == W / 2.0 && y == H / 2.0) {
        another = 1;
    }

    cout << fixed << setprecision(20) << (long double)(H * W / 2.0) << " ";
    cout << another << endl;
}