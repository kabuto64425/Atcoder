#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll A;
    cin >> A;
    float B;
    cin >> B;
    ll C = (B * 100 + 0.001);
    cout << A * C / 100 << endl;
}