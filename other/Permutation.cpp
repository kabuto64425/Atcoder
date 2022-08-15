#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// nPnの順列に対して処理を実行する
void foreach_permutation(int n, std::function<void(int *)> f) {
  int indexes[n];
  for (int i = 0; i < n; i++) indexes[i] = i;
  do {
    f(indexes);
  } while (std::next_permutation(indexes, indexes + n));
}

int main() {
  foreach_permutation(3, [](int *indexes) {
    std::cout << indexes[0] << ',' << indexes[1] << ',' << indexes[2] << std::endl;
  });
}