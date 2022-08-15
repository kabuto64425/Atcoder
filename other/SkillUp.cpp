#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //入力
    ll N, M, X;
    cin >> N >> M >> X;

    vector<ll> price(N);
    vector<vector<ll>> book(N, vector<ll>(M));

    for(ll i = 0; i < N; i++) {
        cin >> price.at(i);
        for(ll j = 0; j < M; j++) {
            cin >> book.at(i).at(j);
        }
    }

    ll ans = -1;
    //処理
    for(ll bit = 0; bit < (1 << N); bit++) {
        ll currentPrice = 0;
        vector<ll> skill(M, 0);
        for(ll i = 0; i < N; i++) {
            if(bit & (1 << i)) {
                currentPrice += price.at(i);
                for(ll j = 0; j < M; j++) {
                    skill.at(j) += book.at(i).at(j);
                }
                bool flag = true;
                for(ll j = 0; j < M; j++) {
                    if(skill.at(j) < X) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    if(ans == -1) {
                        ans = currentPrice;
                    } else {
                        ans = min(ans, currentPrice);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}