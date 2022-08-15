#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B, X;

bool solve(ll mid) {
    ll d = (ll) log10(mid) + 1;
    ll price = A * mid + B * d;
    if(price >= X) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> A >> B >> X;
    ll ok = 1;
    ll ng = 1000000001;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if(solve(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
}