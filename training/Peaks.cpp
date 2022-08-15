#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> height(N);
    for (ll i = 0; i < N; i++) {
      cin >> height.at(i);
    }
    vector<vector<ll>> road(M, vector<ll>(2));
    for (ll i = 0; i < M; i++) {
      cin >> road.at(i).at(0) >> road.at(i).at(1);
    }

    vector<ll> ma(N, 0);
    for(ll i = 0; i < M; i++) {
        ma.at(road.at(i).at(0) - 1) = max(ma.at(road.at(i).at(0) - 1), height.at(road.at(i).at(1) - 1));
        ma.at(road.at(i).at(1) - 1) = max(ma.at(road.at(i).at(1) - 1), height.at(road.at(i).at(0) - 1));
    }

    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        if(height.at(i) > ma.at(i)) {
            ans++;
        }
    }
    cout << ans <<endl;
}