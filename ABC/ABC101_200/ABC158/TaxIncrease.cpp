#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll tax8 = 8;
const ll tax10 = 10;

int main() {
    ll A, B;
    cin >> A >> B;

    ll Amin = ((A * 100) + (tax8 - 1)) / tax8;
    ll Amax = (((A + 1) * 100+ (tax8 - 1)) / tax8 - 1);
    ll Bmin = ((B * 100) + (tax10 - 1)) / tax10;
    ll Bmax = (((B + 1) * 100+ (tax10 - 1)) / tax10 - 1);

    ll ans = -1;
    if(Amax >= Bmin && Amin <= Bmax) {
        ans = max(Amin, Bmin);
    }
    cout << ans << endl;
}