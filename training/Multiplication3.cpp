#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll A;
    cin >> A;
    string B;
    cin >> B;

    bool flag = false;
    int count = 0;

    ll Bdash = 0;

    for(int i = 0; i < B.size(); i++) {
        if(B[i] == '.') {
            flag = true;
        } else {
            Bdash = Bdash * 10 + (ll)(B[i] - '0');
            if(flag) {
                count++;
            }
        }
    }

    ll ans = A * Bdash;
    for(int i = 0; i < count; i++) {
        ans /= 10;
    }

    cout << ans << endl;
}