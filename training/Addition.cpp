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
    int count = 0;
    for (int element : vec) {
        if(element % 2 == 1) {
            count++;
        }
    }

    if(count % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}