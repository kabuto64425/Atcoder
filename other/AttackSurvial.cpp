#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //入力
    ll N, K, Q;
    cin >> N >> K >> Q;

    vector<ll> vec(Q);

    for(ll i = 0; i < Q; i++) {
        cin >> vec.at(i);
    }

    vector<ll> score(N, K - Q);
    //処理
    for(ll i = 0; i < Q; i++) {
        score.at(vec.at(i) - 1)++;
    }

    for(ll i = 0; i < N; i++) {
        cout << ((score.at(i) > 0)? "Yes" : "No") << endl;
    }
}