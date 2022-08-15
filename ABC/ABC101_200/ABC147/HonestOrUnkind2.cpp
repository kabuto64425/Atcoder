#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<vector<vector<ll>>> vec(N);
    for(ll i = 0; i < N; i++) {
        ll A;
        cin >> A;
        vector<vector<ll>> vec2(A);
        for(ll j = 0; j < A; j++) {
            vector<ll> vec3(2);
            cin >> vec3.at(0) >> vec3.at(1);
            vec2.at(j) = vec3;
        }
        vec.at(i) = vec2;
    }

    ll ans = 0;
    for(ll bit = 0; bit < (1 << N); bit++) {
        bool flag = true;
        ll count = 0;
        for(ll i = 0; i < N; i++) {
            if(bit & (1 << i)) {
                count++;
                vector<vector<ll>> vec2 = vec.at(i);
                for(ll j = 0; j < vec2.size(); j++) {
                    vector<ll> vec3 = vec2.at(j);
                    ll aite = vec3.at(0) - 1;
                    if(bit & (1 << aite)) {
                        if(vec3.at(1) != 1) {
                            flag = false;
                        }
                    } else {
                        if(vec3.at(1) != 0) {
                            flag = false;
                        }
                    }
                }
            }
        }
        if(flag) {
            ans = max(ans, count);
        }
    }
    cout << ans << endl;
}