#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    char S, Y;
    cin >> S >> Y;
    if(S == 'Y') {
        cout << (char)(Y - ('a' - 'A')) << endl;
    } else {
        cout << Y << endl;
    }
}