#include <bits/stdc++.h>
using namespace std;

int main() {
    //入力
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
      cin >> vec.at(i);
    }

    //処理

    bool flag = true;
    int orbit = 0;
    while(flag) { 
      for(int i = 0; i < n; i++) {
          if(vec.at(i) % 2 == 0) {
              vec.at(i) = vec.at(i) / 2;
          } else {
              flag = false;
              break;
          }
      }
      if(flag) {
          orbit++;
      }
    }
    cout << orbit << endl;
}