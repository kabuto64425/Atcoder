#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, X;
    cin >> N >> X;
    string S;
    cin >> S;
    deque<char> que;
    for(ll i = 0; i < N; i++) {
        char c = S.at(i);
        if(c != 'U') {
            que.push_back(c);
        } else {
            if(que.empty()){
                que.push_back(c);
            } else {
                char back = que.back();
                if(back != 'U') {
                    que.pop_back();
                } else {
                    que.push_back(c);
                }
            }
        }
    }
    ll ans = X;
    while(!que.empty()) {
        char c = que.front();
        que.pop_front();
        if(c == 'U') {
            ans /= 2;
        } else if(c == 'L') {
            ans *= 2;
        }else if(c == 'R') {
            ans = ans * 2 + 1;
        }
    }
    cout << ans << endl;
    return 0;
}