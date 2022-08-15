#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    ll index = A - 1;
    ll lcmCD = lcm(C, D);
    ll left = index - (index / C) - (index / D) + (index / lcmCD);
    ll right = B - (B / C) - (B / D) + (B / lcmCD);
    cout << right - left << endl;
}