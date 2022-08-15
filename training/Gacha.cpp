#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //入力
    ll N;
    cin >> N;
    vector<string> vec(N);
    for (ll i = 0; i < N; i++) {
        cin >> vec.at(i);
    }

    //処理
    sort(vec.begin(), vec.end());

    ll ans = 1;
    for (ll i = 0; i < N - 1; i++) {
        if(vec.at(i) != vec.at(i + 1)) {
            ans++;
        }
    }
    cout << ans << endl;
}