#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll L;
    cin >> L;
    long double ans = L * L * L / (long double)27;
    cout << fixed << setprecision(20) << ans << endl;
}