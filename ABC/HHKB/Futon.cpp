#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll H, W;
    cin >> H >> W;
    vector<string> vec(H);

    for(ll i = 0; i < H; i++) {
        cin >> vec.at(i);
    }

    ll ans = 0;
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if((j < W - 1) && vec.at(i).at(j) == '.' && vec.at(i).at(j + 1) == '.') {
                ans++;
            }
            if((i < H - 1) && vec.at(i).at(j) == '.' && vec.at(i + 1).at(j) == '.') {
                ans++;
            }
        }
    }
    cout << ans << endl;
}