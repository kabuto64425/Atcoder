#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    ll N;
    cin >> N;
    string S;
    cin >> S;
    
    tuple<ll, ll, ll> rgb = {0, 0, 0};

    for(ll i = 0; i < S.length(); i++) {
        if(S.at(i) == 'R') {
            get<0>(rgb)++;
        } else if(S.at(i) == 'G') {
            get<1>(rgb)++;
        } else {
            get<2>(rgb)++;
        }
    }

    ll ans = get<0>(rgb) * get<1>(rgb)* get<2>(rgb);

    for(ll i = 1; i <= N - 2; i++) {
        for(ll j = i + 1; j <= N - 1; j++) {
            ll k = 2 * j - i;
            char Si = S.at(i - 1);
            char Sj = S.at(j - 1);
            if(k <= N) {
                char Sk = S.at(k - 1);
                if(Si != Sj && Si != Sk && Sj != Sk) {
                    ans--;
                }
            }
        }
    }

    cout << ans << endl;
}