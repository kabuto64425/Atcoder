#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string S;
  cin >> S;
  
  ll ans = 0;
  ll current = 0;
  for(ll i = 0; i < S.length(); i++) {
    if(S.at(i) == 'R') {
      current++;
    } else {
      ans = max(ans, current);
      current = 0;
    }
  }

  ans = max(ans, current);
  cout << ans << endl;
}