#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  string C;
  cin >> N;
  cin >> C;

  int split = 0;
  
  for(int i = 0; i < N; i++) {
    if(C[i] == 'R') {
      split++;
    }
  }

  int count = 0;

  for(int i = 0; i < split; i++) {
    if(C[i] == 'R') {
      count++;
    }
  }

  cout << (split - count) << endl;
}