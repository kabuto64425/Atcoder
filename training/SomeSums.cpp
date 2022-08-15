#include <bits/stdc++.h>
using namespace std;

int main() {
    //入力
    int N, A, B;
    cin >> N >> A >> B;

    //処理

    int result = 0;

    for(int i = 0; i < N; i++) {
        int currentNum = (i + 1);
        int currentSum = 0;
        while(true) {
            currentSum += currentNum % 10;
            currentNum = currentNum / 10;
            if(currentNum == 0) {
                break;
            }
        }

        if(currentSum >= A && currentSum <= B) {
            result += (i + 1);
        }

    }
    cout << result << endl;
}