#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //入力
    string N;
    cin >> N;
    ll sum = 0;
    for(ll i =0; i < N.length(); i++) {
        sum += (N.at(i) - '0');
    }
    cout << ((sum % 9 ==0)? "Yes" : "No") << endl;
}