#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll X;
    cin >> X;
    vector<ll> primes;
    ll index = 2;
    while(true) {
        ll flag = true;
        for(ll i = 0; i < primes.size(); i++) {
            if(index % primes.at(i) == 0) {
                flag = false;
                break;
            }
        }
        if(flag) {
            primes.push_back(index);
            if(index >= X) {
                break;
            }
        }
        index++;
    }

    cout << index << endl;
}