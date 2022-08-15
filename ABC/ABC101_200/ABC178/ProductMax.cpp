#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //入力
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = max(a * c, a * d);
    ans = max(ans, b * c);
    ans = max(ans, b * d);
    cout << ans << endl;
}