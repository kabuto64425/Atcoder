#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll L, R;
    cin >> L >> R;

    ll count = 0;
    vector<ll> vec;
    while(true) {
        if(count >= 2019) {
            break;
        }
        if((L + count) > R) {
            break;
        }
        vec.push_back((L + count) % 2019);

        count++;
    }

    ll ans = 2019;

    for(ll i = 0; i < vec.size() - 1; i++) {
        for(ll j = 1; j < vec.size(); j++) {
            ans = min(ans, vec.at(i) * vec.at(j) % 2019);
        }
    }
    cout << ans << endl;
}