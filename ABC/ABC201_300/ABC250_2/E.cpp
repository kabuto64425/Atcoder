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
    vector<ll> a(N);
    vector<ll> b(N);
    for(ll i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    for(ll i = 0; i < N; i++) {
        cin >> b.at(i);
    }

    ll Q;
    cin >> Q;
    vector<ll> x(Q), y(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> x.at(i) >> y.at(i);
        x.at(i)--;
        y.at(i)--;
    }

    set<ll> seta;
    vector<ll> sizea(N);
    vector<ll> na;
    for(ll i = 0; i < N; i++) {
        if(!seta.count(a.at(i))) {
            seta.insert(a.at(i));
            na.push_back(a.at(i));
        }
        sizea.at(i) = seta.size();
    }
    set<ll> setb;
    vector<ll> sizeb(N);
    vector<ll> nb;
    for(ll i = 0; i < N; i++) {
        if(!setb.count(b.at(i))) {
            setb.insert(b.at(i));
            nb.push_back(b.at(i));
        }
        sizeb.at(i) = setb.size();
    }
    
    ll M = min(na.size(), nb.size());
    set<ll> setZ;
    vector<ll> diffVec(M);
    for(ll i = 0; i < M; i++) {
        if(setZ.count(na.at(i))) {
            setZ.erase(na.at(i));
        } else {
            setZ.insert(na.at(i));
        }
        if(setZ.count(nb.at(i))) {
            setZ.erase(nb.at(i));
        } else {
            setZ.insert(nb.at(i));
        }
        diffVec.at(i) = setZ.size();
    }

    for(ll i = 0; i < Q; i ++) {
        ll sai = sizea.at(x.at(i));
        ll sbi = sizeb.at(y.at(i));
        if(sai != sbi) {
            cout << "No" << endl;
            continue;
        }
        if(diffVec.at(sai - 1) != 0) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }
    return 0;
}