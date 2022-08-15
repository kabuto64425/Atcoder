#include <bits/stdc++.h>
using namespace std;

int main() {
    //入力
    int N;
    cin >> N;
    vector<int> vec(N * 3);
    for (int i = 0; i < N * 3; i++) {
      cin >> vec.at(i);
    }

    //処理
    int time = 0;
    int x = 0;
    int y = 0;
    bool can = true;
    for (int i = 0; i < N; i++) {
        int dt = vec.at(i * 3) - time;
        int dist = abs(vec.at(i * 3 + 1) - x) + abs(vec.at(i * 3 + 2) - y);

        if(dt < dist) {
            can = false;
            break;
        }

        if((dt % 2) != (dist % 2)) {
            can = false;
            break;
        }

        time = vec.at(i * 3);
        x = vec.at(i * 3 + 1);
        y = vec.at(i * 3 + 2);
    }

    if(can) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}