#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //入力
    ll N, X, T;
    cin >> N >> X >> T;
    cout << ((N + (X - 1)) / X) * T << endl;
}