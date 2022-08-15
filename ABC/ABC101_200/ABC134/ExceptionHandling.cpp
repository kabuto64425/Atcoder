#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);

    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    vector<ll> B = A;
    sort(B.begin(), B.end(), greater<int>());

    for(ll i = 0; i < N; i++) {
        if(A.at(i) == B.at(0)) {
            cout << B.at(1) << endl;
        } else {
            cout << B.at(0) << endl;
        }
    }
}