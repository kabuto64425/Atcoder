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

template<typename T>
struct BIT {
    int n;
    vector<T> d;
    BIT(int n=0):n(n),d(n+1) {}
    void add(int i, T x=1) {
        for (i++; i <= n; i += i&-i) {
            d[i] += x;
        }
    }
    // 付け足した
    void update(int i, T x=1) {
        ll m = get(i);
        for (i++; i <= n; i += i&-i) {
            d[i] += (x - m);
        }
    }
    T sum(int i) {
        T x = 0;
        for (i++; i; i -= i&-i) {
            x += d[i];
        }
        return x;
    }
    T sum(int l, int r) {
        return sum(r-1) - sum(l-1);
    }
    // 付け足した
    T get(int i) {
        assert(0 <= i && i < n);
        if(i == 0) {
            return sum(0);
        }
        return sum(i) - sum(i - 1);
    }
    // 付け足した
    // ※合計値との大小比較で求めるため、nametypeがmintのときの使用は非推奨
    // 2分探索のため、配列に負の数が含まれるときの使用も非推奨
    int lower_bound(T w) {
        if (w <= 0) return 0;
        int x = 0;
        int k = 1;
        while (k * 2 <= n) k *= 2;
        for (; k > 0; k /= 2) {
            if (x + k <= n && d[x + k] < w) {
                w -= d[x + k];
                x += k;
            }
        }
        return x;
    }
};

int main(){
    ll L, Q;
    cin >> L >> Q;
    vector<ll> c(Q), x(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> c.at(i) >> x.at(i);
    }
    vector<ll> cuts;
    cuts.push_back(0);
    cuts.push_back(L);
    for(ll i = 0; i < Q; i++) {
        if(c.at(i) == 1){
            cuts.push_back(x.at(i));
        }
    }
    sort(ALL(cuts));
    ll N = cuts.size();
    BIT<int> BIT(N);
    BIT.add(N - 1, 1);
    for(ll i = 0; i < Q; i++) {
        if(c.at(i) == 1){
            ll j = lower_bound(ALL(cuts), x.at(i)) - cuts.begin();
            BIT.add(j, 1);
        } else {
            ll j = lower_bound(ALL(cuts), x.at(i)) - cuts.begin();
            ll val = BIT.sum(0, j);
            ll jl;
            ll jr;
            if(val == 0) {
                jl = 0;
            } else {
                jl = BIT.lower_bound(val);
            }
            jr = BIT.lower_bound(val + 1);
            cout << cuts.at(jr) - cuts.at(jl) << endl;
        }
    }
    return 0;
}