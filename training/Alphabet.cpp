#include <bits/stdc++.h>
using namespace std;

int main() {
    //入力
    char alpha;
    cin >> alpha;

    //処理
    char res;
    if('a' <= alpha && alpha <= 'z') {
        res = 'a';
    }
    if('A' <= alpha && alpha <= 'Z') {
        res = 'A';
    }

    cout << res << endl;
}