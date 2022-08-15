#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i], --A[i];

    deque<int> a; // 繰り返しの部分
    vector<bool> seen(N, false); // 一度見たかどうか
    ll cur = 0;
    while(true) {
        if(seen.at(cur)) {
            while(a.front() != cur) {
                a.pop_front();
                K--;

                if(K == 0) {
                    cout << a.front() + 1 << endl;
                    return 0;
                }
            }
            break;
        }

        seen.at(cur) = true;
        a.push_back(cur);
        cur = A.at(cur);
    }

    cout << a.at(K % a.size()) + 1 << endl;
}