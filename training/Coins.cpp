#include <bits/stdc++.h>
using namespace std;

int main() {
    //入力
    int c500, c100, c50, target;
    cin >> c500 >> c100 >> c50 >> target;

    //処理
    int result = 0;
    for(int i = 0; i < (c500 + 1); i++) {
        for(int j = 0; j < (c100 + 1); j++) {
            for(int k = 0; k < (c50 + 1); k++) {
                if((i * 500 + j * 100 + k * 50) == target) {
                    result++;
                }
            }
        }
    }
    cout << result << endl;
}