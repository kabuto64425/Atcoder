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

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll Q;
    cin >> Q;
    vector<ll> T(Q), A(Q), B(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> T.at(i) >> A.at(i) >> B.at(i);
        A.at(i)--;
        B.at(i)--;
    }
    string front = S.substr(0, N);
    string back = S.substr(N, N);
    for(ll i = 0; i < Q; i++) {
        if(T.at(i) == 2) {
            swap(front, back);
        } else {
            if(A.at(i) < N and B.at(i) < N) {
                char &c1 = front.at(A.at(i));
                char &c2 = front.at(B.at(i));
                swap(c1, c2);
            } else if(A.at(i) < N and B.at(i) >= N) {
                char &c1 = front.at(A.at(i));
                char &c2 = back.at(B.at(i) - N);
                swap(c1, c2);
            } else {
                char &c1 = back.at(A.at(i) - N);
                char &c2 = back.at(B.at(i) - N);
                swap(c1, c2);
            }
        }
    }
    cout << front << back << endl;
    return 0;
}