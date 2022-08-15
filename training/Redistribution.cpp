#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;

ll recursion(int x, vector<long long> &memo){
    if(x == 0) {
        return 1;
    }
    if(x == 1) {
        return 0;
    }
    if(x == 2) {
        return 0;
    }
    
    if(memo.at(x - 1) != -1) {
        return memo.at(x - 1);
    }

    return memo.at(x - 1) = (recursion(x - 1, memo) + recursion(x - 3, memo)) % mod;
}

int main() {
    //入力
    int S;
    cin >> S;

    //処理
    // メモ用配列 (-1 は未計算であることを表す)
    vector<long long> memo(S, -1);
    cout << recursion(S, memo) << endl;
}