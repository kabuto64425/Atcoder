#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    string S;
    cin >> N;
    cin >> S;
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        ll coutA = 0;
        ll coutT = 0;
        ll coutG = 0;
        ll coutC = 0;
        for(ll j = i; j < N; j++) {
            if(S.at(j) == 'A') {
                coutA++;
            }
            if(S.at(j) == 'T') {
                coutT++;
            }
            if(S.at(j) == 'G') {
                coutG++;
            }
            if(S.at(j) == 'C') {
                coutC++;
            }
            if(coutA == coutT && coutG == coutC) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}