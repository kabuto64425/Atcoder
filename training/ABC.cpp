#include <bits/stdc++.h>
using namespace std;

int main() {
    //入力
    int N;
    cin >> N;

    //処理
    int count = 0;
    for(int a = 1; a <= (N - 1); a++) {
        count += (N - 1) / a;
    }

    cout << count << endl;
}