#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //入力
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> bookA(N);
    for (ll i = 0; i < N; i++) {
      cin >> bookA.at(i);
    }
    vector<ll> bookB(M);
    for (ll i = 0; i < M; i++) {
      cin >> bookB.at(i);
    }

    // 処理
    ll i = 0;
    ll j = M;

    ll timeA = 0;
    /*
      accumulate使用時は第3引数を必ず0LLに！
    */
    ll timeB = accumulate(bookB.begin(), bookB.end(), 0LL);

    ll ans = 0;

    while(true) {
        while(true) {
            if(timeA + timeB <= K) {
                ans = max(ans, i + j);
                break;
            }
            if(j <= 0) {
                break;
            }
            timeB = timeB - bookB.at(j - 1);
            j--;
        }
        if(i >= N) {
            break;
        }
        timeA = timeA + bookA.at(i);
        i++;
    }

    cout << ans << endl;
}