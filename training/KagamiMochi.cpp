#include <bits/stdc++.h>
using namespace std;

int main() {
    //入力
    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
      cin >> vec.at(i);
    }

    //処理
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    cout << vec.size() << endl;
}