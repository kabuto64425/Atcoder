#include <bits/stdc++.h>
using namespace std;

// a < b か？
bool comp(char a, char b) {
    if (a == 'R') return (b == 'P');
    else if (a == 'P') return (b == 'S');
    else return (b == 'R');
}
// a と b のどちらが勝つか？
char which(char a, char b) {
    if (comp(a, b)) return b;
    else return a;
}

vector<long long> two;
vector<vector<char>> dp;
char solve(int N, const string &S, int K, int offset) {
    if (K == 0) return S[offset];
    if (dp[K][offset] != '?') return dp[K][offset]; 
    long long offset2 = (offset + two[K-1]) % N;
    char zenhan = solve(N, S, K-1, offset);
    char kouhan = solve(N, S, K-1, offset2);
    return dp[K][offset] = which(zenhan, kouhan);
}

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;
    two.assign(K+1, 1);
    for (int n = 0; n < K; ++n) two[n+1] = two[n] * 2 % N;
    dp.assign(K+1, vector<char>(N+1, '?'));
    cout << solve(N, S, K, 0) << endl;
}