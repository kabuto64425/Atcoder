#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll X;
    cin >> X;

    ll money = 100;
    ll year = 0; 
    while(true) {
      if(money >= X) {
        break;
      }
      money = money + money / 100;
      year++;
    }

    cout << year << endl;
}