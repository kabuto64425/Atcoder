#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //入力
    ll X;
    cin >> X;
    vector<bool> isPrime(X + 1, true);
    isPrime.at(0) = false;
    isPrime.at(1) = false;
    for(ll i = 2; i <= X; i++) {
        /* エラトステネスの篩 */
        if(!isPrime.at(i)) {
            continue;
        }

        for(ll j = 2; i * j <= X; j++) {
            isPrime.at(i * j) = false;
        }
    }
    
    while(true) {
        bool flag = true;
        for(ll i = 2; i * i <= X; i++) {
            if(!isPrime.at(i)) {
                continue;
            }
            if(X % i == 0) {
                flag = false;
                break;
            }
        }
        if(flag) {
            break;
        }
        X++;
    }

    cout << X << endl;
}