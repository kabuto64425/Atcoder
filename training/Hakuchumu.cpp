#include <bits/stdc++.h>
using namespace std;

int main() {
    //入力
    string S;
    cin >> S;

    //処理
    vector<string> vec{"dream", "dreamer", "erase", "eraser"};
    string T;

    // 反転させると、各要素で前方一致しなくなるから
    reverse(S.begin(), S.end());

    for (string& element : vec) {
        reverse(element.begin(), element.end());
    }

    while(true) {
        bool flag = false;
        for (string& element : vec) {
            string current = T + element;
            if(S.compare(current) == 0) {
                //OK
                cout << "YES" << endl;
                return 0;
            }
            if(current.size() <= S.size() && S.compare(0, current.size(), current) == 0) {
                // 前方一致
                T = current;
                flag = true;
                break;
            }
        }

        if(!flag) {
            cout << "NO" << endl;
            return 0;
        }
    }
}