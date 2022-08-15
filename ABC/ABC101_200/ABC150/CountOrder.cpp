#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    vector<ll> A(N);
    vector<ll> B(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    for(ll i = 0; i < N; i++) {
        cin >> B.at(i);
    }

    vector<ll> jisyo(N);
    for(ll i = 0; i < N; i++) {
        jisyo.at(i) = (i+1);
    }

    ll count = 1;
    ll ansA;
    ll ansB;
    do {
        if(jisyo == A) {
            ansA = count;
        }
        if(jisyo == B) {
            ansB = count;
        }
        count++;
    } while (next_permutation(jisyo.begin(), jisyo.end()));
    
    cout << abs(ansA - ansB) << endl;
}