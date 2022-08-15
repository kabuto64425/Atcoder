#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll X;
    cin >> X;

    ll leftLimit = 0;
    while(pow(leftLimit, 5) - pow(leftLimit - 1, 5) <= X) {
        leftLimit--;
    }
    ll rightLimit = 0;
    while(pow(rightLimit, 5) - pow(rightLimit - 1, 5) <= X) {
        rightLimit++;
    }
    for(ll A = leftLimit; A <= rightLimit; A++) {
        for(ll B = leftLimit; B <= rightLimit; B++) {
            ll judge = pow(A, 5) - pow(B, 5);
            if(judge == X) {
                cout << A << " " << B << endl;
                return 0;
            }
        }
    }
}