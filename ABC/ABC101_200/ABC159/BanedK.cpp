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

    vector<ll> nums(N + 1, 0);
    ll sum = 0;
    for(ll i = 0; i < N; i++) {
        nums.at(A.at(i)) += 1;
    }

    for(ll i = 1; i <= N; i++) {
        sum += nums.at(i) * (nums.at(i) - 1) / 2; 
    }

    for(ll i = 0; i < N; i++) {
        cout << (sum - nums.at(A.at(i)) + 1) << endl;
    }
}