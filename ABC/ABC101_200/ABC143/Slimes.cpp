#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll ans = 1;
    for(ll i = 0; i < N - 1; i++) {
        if(S.at(i) != S.at(i + 1)) {
            ans++;
        }
    }
    cout << ans << endl;
}