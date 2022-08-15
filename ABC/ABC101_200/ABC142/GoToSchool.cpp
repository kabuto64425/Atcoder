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
    vector<ll> B(N, -1);
    for(ll i = 0; i < N; i++) {
        B.at(A.at(i) - 1) = i + 1;
    }
    for(ll i = 0; i < N; i++) {
        cout << B.at(i);
        if(i != N - 1) {
            cout << " ";
        }
    }
    cout << endl;
}