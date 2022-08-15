#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
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
        add(i, x - m);
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
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    vector<ll> pos;
    for(const ll &a : A) {
        pos.push_back(a);
    }
    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());
    ll M = pos.size();
    BIT<mint> Z(M);
    for(ll i = 0; i < N; i++) {
        ll j = lower_bound(pos.begin(), pos.end(), A.at(i)) - pos.begin();
        Z.add(j, ((mint) 2).pow(i));
    }

    mint ans = 0;

    for(ll i = 0; i < N; i++) {
        ll j = lower_bound(pos.begin(), pos.end(), A.at(i)) - pos.begin();
        mint current = Z.sum(j, M);
        current -= ((mint) 2).pow(i);
        current /= ((mint) 2).pow(i + 1);
        ans += current;
        Z.add(j, -((mint) 2).pow(i));
    }
    cout << ans.val() << endl;
    return 0;
}