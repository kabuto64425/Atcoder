#include <bits/stdc++.h>
using namespace std;

int main() {
    //入力
    int N, Y;
    cin >> N >> Y;

    //処理
    for(int i = 0; i <= N; i++) {
        int z = N - i;
        for(int j = 0; j <= i; j++) {
            int y = i - j;
            int x = j;
            int total = x * 10000 + y * 5000 + z * 1000;
            if(total == Y) {
                cout << x << " " << y << " " << z << endl;
                return 0;
            }
        }
    }

    cout << "-1 -1 -1" << endl;
}