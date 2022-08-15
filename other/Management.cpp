#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //入力
    ll N;
    cin >> N;
    vector<ll> vec(N - 1);

    for(ll i = 0; i < N - 1; i++) {
        cin >> vec.at(i);
    }

    //処理
    vector<ll> buka(N, 0);
    for(ll i = 0; i < N - 1; i++) {
        buka.at(vec.at(i) - 1)++;
    }

    for(ll i = 0; i < N; i++) {
        cout << buka.at(i) << endl;
    }
}