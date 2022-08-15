#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //入力
    ll N;
    cin >> N;

    //処理
    string str;

    while(true) {
        N--;
        str += (char)('a' + (N % 26));
        N = N / 26;
        if(N == 0) {
            break;
        }
    }

    reverse(str.begin(), str.end());
    cout << str << endl;
}