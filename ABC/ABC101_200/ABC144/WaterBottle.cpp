#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    long double a, b, x;
    cin >> a >> b >> x;
    long double h = 2 * (a * a * b - x) / (a * a);
    if(h > b) {
        long double l = (2 * x) / (a * b);
        cout << fixed << setprecision(20) << (atan2(b, l) * 180) / M_PI << endl;
    } else {
        cout << fixed << setprecision(20) << (atan2(h, a) * 180) / M_PI << endl;
    }
}