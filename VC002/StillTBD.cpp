#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string S;
    cin >> S;
    ll year = atoi(S.substr(0, 4).c_str());
    ll month = atoi(S.substr(5, 2).c_str());
    ll day = atoi(S.substr(8, 2).c_str());
    if(month <= 4) {
        cout << "Heisei" << endl;
    } else {
        cout << "TBD" << endl;
    }
}