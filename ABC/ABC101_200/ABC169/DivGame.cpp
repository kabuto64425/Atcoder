#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    ll limit = sqrt(N);

    ll ans = 0;

    for(ll i = 2; i <= limit; i++) {
        if(N % i != 0) {
            continue;
        }
        ll ex = 0;
        while(N % i == 0) {
            N = N / i;
            ex++;
        }

        ll j = 1;
        while(ex >= j) {
            ans++;
            ex -= j;
            j++;
        }
    }
    if(N != 1) {
        ans++;
    }
    cout << ans << endl;
}