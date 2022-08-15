#include <bits/stdc++.h>
using namespace std;

int main() {
    //入力
    int N;
    int K;
    cin >> N;
    cin >> K;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
      cin >> vec.at(i);
    }

    //処理
    sort(vec.begin(), vec.end());

    int sum = 0;

    for(int i = 0; i < K; i++) {
        sum += vec.at(i);
    }

    cout << sum << endl;
}