#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

class BIT {
public:
    int size_ = 1;
    vector<long long> bit;

    void init(int sz) {
        size_ = sz + 2;
        bit.resize(size_ + 2, 0);
    }
    void add(int pos, long long x) {
        pos++;
        while (pos <= size_) {
            bit[pos] += x;
            pos += (pos & -pos);
        }
    }
    long long sum(int pos) {
        long long s = 0; pos++;
        while (pos >= 1) {
            s += bit[pos];
            pos -= (pos & -pos);
        }
        return s;
    }
};

bool sort_by(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> LR(M);
    for(pair<ll, ll> &lr : LR) {
        cin >> lr.first >> lr.second;
    }
    vector<ll> v1(N + 1);
    for(const pair<ll, ll> &lr : LR) {
        v1.at(lr.first)++;
        v1.at(lr.second)++;
    }
    ll answer1 = 0;
    for(ll i = 1; i <= N; i++) {
        answer1 += v1.at(i) * (v1.at(i) - 1) / 2;
    }
    
    vector<ll> v2(N + 1);
    for(const pair<ll, ll> &lr : LR) {
        v2.at(lr.second)++;
    }
    for(ll i = 1; i <= N; i++) {
        v2.at(i) += v2.at(i - 1);
    }
    ll answer2 = 0;
    for(const pair<ll, ll> &lr : LR) {
        answer2 += v2.at(lr.first - 1);
    }

    sort(LR.begin(), LR.end(), sort_by);
    BIT Z;
    Z.init(N);
    vector<ll> v3(N + 1);
    ll answer3 = 0;
    for(const pair<ll, ll> &lr : LR) {
        ll ret = Z.sum(lr.second) - Z.sum(lr.first);
        answer3 += ret;
        Z.add(lr.first, 1);
    }

    ll total = M * (M - 1) / 2;

    cout << total - answer1 - answer2 - answer3 << endl;
    return 0;
}