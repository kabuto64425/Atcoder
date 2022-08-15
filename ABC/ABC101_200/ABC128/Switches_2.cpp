#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, vector<ll>>> ks(M);
    for(ll i = 0; i < M; i++) {
        cin >> ks.at(i).first;
        vector<ll> s(ks.at(i).first);
        ks.at(i).second = s;
        for(ll j = 0; j < ks.at(i).first; j++) {
            cin >> ks.at(i).second.at(j);
        }
    }

    vector<ll> p(M);
    for(ll i = 0; i < M; i++) {
        cin >> p.at(i);
    }

    ll ans = 0;
    for(ll bit = 0; bit < (1 << N); bit++) {
        bool flag = true;
        for(ll i = 0; i < M; i++) {
            ll k = ks.at(i).first;
            vector<ll> s = ks.at(i).second;
            ll count = 0;
            for(ll j = 0; j < k; j++) {
                if(bit & (1 << (s.at(j) - 1))) {
                    count++;
                }
            }
            if(count % 2 != p.at(i)) {
                flag = false;
            }
        }
        if(flag) {
            ans++;
        }
    }

    cout << ans << endl;
}