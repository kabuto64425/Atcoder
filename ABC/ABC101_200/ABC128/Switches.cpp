#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;

    vector<pair<ll, vector<ll>>> lights(M);

    for(ll i = 0; i < M; i++) {
        cin >> lights.at(i).first;
        vector<ll> joken(lights.at(i).first);
        lights.at(i).second = joken;
        for(ll j = 0; j < lights.at(i).first; j++) {
            cin >> lights.at(i).second.at(j);
        }
    }

    vector<ll> p(M);
    for(ll i = 0; i < M; i++) {
        cin >> p.at(i);
    }

    ll ans = 0;

    for(ll bit = 0; bit < (1 << N); bit++) {
        string str = "";
        vector<ll> current = p;
        for(ll i = 0; i < N; i++) {
            if(bit & (1 << i)) {
                str = "1" + str;
                for(ll j = 0; j < M; j++) {
                    vector<ll> joken = lights.at(j).second;
                    for(ll k = 0; k < lights.at(j).first; k++) {
                        if((i + 1) == joken.at(k)) {
                            current.at(j) = (current.at(j) + 1) % 2;
                        }
                        //cout << joken.at(k);
                    }
                    //cout << endl;
                }
            } else {
                str = "0" + str;
            }
        }
        bool flag = true;
        for(ll j = 0; j < M; j++) {
            if(current.at(j) != 0) {
                flag = false;
            }
            //cout << current.at(j);
        }

        if(flag) {
            ans++;
        }
        //cout << endl;
    }

    cout << ans <<endl;
}