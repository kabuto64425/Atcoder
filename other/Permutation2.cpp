#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    // 見込みなしと判断
    if (s + 1 < rest) return;
    // sを使わないパターン
    recursive_comb(indexes, s - 1, rest, f);
    // sを使うパターン
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

void recursive_h(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    // sを使わないパターン
    recursive_h(indexes, s - 1, rest, f);
    // sを使うパターン
    indexes[rest - 1] = s;
    recursive_h(indexes, s, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

// nPnの順列に対して処理を実行する
void foreach_permutation(int n, std::function<void(int *)> f) {
  int indexes[n];
  for (int i = 0; i < n; i++) indexes[i] = i;
  do {
    f(indexes);
  } while (std::next_permutation(indexes, indexes + n));
}

// nPkの順列に対して処理を実行する
void foreach_permutation(int n, int k, std::function<void(int *)> f) {
  foreach_comb(n, k, [&](int *c_indexes) {
    foreach_permutation(k, [&](int *p_indexes) {
      int indexes[k];
      for (int i = 0; i < k; i++) {
        indexes[i] = c_indexes[p_indexes[i]];
      }
      f(indexes);
    });
  });
}

// nHkの組み合わせに対して処理を実行する
void foreach_h(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_h(indexes, n - 1, k, f);
}

int main() {
  foreach_comb(
      4, 2, [](int *indexes) { std::cout << indexes[0] << ',' << indexes[1] << std::endl; });
}