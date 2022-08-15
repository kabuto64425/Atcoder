#include <bits/stdc++.h>
using namespace std;
 
int main(){
  double A, B, H, M;
  cin >> A >> B >> H >> M;
  long double ans;
  ans = sqrt(A * A + B * B - 2 * A * B * cos((11 * M / 360 - H / 6) * M_PI));
  cout << fixed << setprecision(20) << ans << endl;
}