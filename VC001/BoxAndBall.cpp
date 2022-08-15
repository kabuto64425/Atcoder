#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> xy(M);
    for(ll i = 0; i < M; i++) {
        cin >> xy.at(i).first >> xy.at(i).second;
    }

    vector<pair<ll, bool>> balls(N, make_pair(1, false));
    balls.at(0).second = true;
    for(ll i = 0; i < M; i++) {
        if(balls.at(xy.at(i).first - 1).second) {
            balls.at(xy.at(i).second - 1).second = true;
        }

        balls.at(xy.at(i).first - 1).first -= 1;
        balls.at(xy.at(i).second - 1).first += 1;

        if(balls.at(xy.at(i).first - 1).first == 0) {
            balls.at(xy.at(i).first - 1).second = false;
        }
    }

    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        if(balls.at(i).second) {
            ans++;
        }
    }
    cout << ans << endl;
}