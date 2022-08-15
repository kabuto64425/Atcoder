#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //入力
    ll H, W, K;
    cin >> H >> W >> K;
    vector<string> vec(H);
    for (ll i = 0; i < H; i++) {
      cin >> vec.at(i);
    }

    //処理
    ll ans = 0;
    for(ll bit1 = 0; bit1 < (1 << H); bit1++) {
        for(ll bit2 = 0; bit2 < (1 << W); bit2++) {
            vector<string> vec2(H);
            copy(vec.begin(), vec.end(), vec2.begin());
            for(ll i = 0; i < H; i++) {
                if(bit1 & (1 << i)) {
                    vec2.at(i).replace(vec2.at(i).begin(), vec2.at(i).end(), '.', 'R');
                    vec2.at(i).replace(vec2.at(i).begin(), vec2.at(i).end(), '#', 'R');
                }
            }
            for(ll i = 0; i < W; i++) {
                if(bit2 & (1 << i)) {
                    for(ll j = 0; j < H; j++) {
                        vec2.at(j)[i] = 'R';
                    }
                }
            }
            ll count = 0;
            for(ll i = 0; i < H; i++) {
                for(ll j = 0; j < W; j++) {
                    if(vec2.at(i)[j] == '#') {
                        count++;
                    }
                }
            }
            if(count == K) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}