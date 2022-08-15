#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    if(A + B + C + D == 0) {
        cout << "Yes" << endl;
        return 0;
    } else if(A + B + C == D) {
        cout << "Yes" << endl;
        return 0;
    } else if(A + B + D == C) {
        cout << "Yes" << endl;
        return 0;
    } else if(A + B == C + D) {
        cout << "Yes" << endl;
        return 0;
    } else if(A + C + D == B) {
        cout << "Yes" << endl;
        return 0;
    } else if(A + C == B + D) {
        cout << "Yes" << endl;
        return 0;
    } else if(A + D == B + C) {
        cout << "Yes" << endl;
        return 0;
    } else if(A == B + C + D) {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
}