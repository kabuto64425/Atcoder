#include <bits/stdc++.h>
using namespace std;
const long long mod=1000000007;

long long powmod(long long x,long long y){
    long long res=1;
    for(long long i=0; i < y; i++){
        res = res * x % mod;
    }
    return res;
}

int main() {
    //入力
    int N;
    cin >> N;

    //処理
    long long answer = powmod(10, N) - powmod(9, N) - powmod(9, N) + powmod(8, N);
    // 余りを求める
    answer %= mod;
    // マイナスの場合、プラスにしないといけない
    answer = (answer + mod) % mod;
    cout << answer << endl;
}