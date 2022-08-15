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

template<typename T>
struct BIT {
    int n;
    vector<T> d;
    BIT(int n=0):n(n),d(n+1) {}
    void add(int i, T x=1) {
        assert(0 <= i && i < n);
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
        assert(0 <= i && i < n);
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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> c(N + 1);
    for(ll i = 1; i <= N; i++) {
        cin >> c.at(i);
    }
    vector<tuple<ll, ll, ll>> query(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> get<0>(query.at(i)) >> get<1>(query.at(i));
        get<2>(query.at(i)) = i;
    }
    for(ll i = 0; i < Q; i++) {
        swap(get<0>(query.at(i)), get<1>(query.at(i)));
    }
    sort(ALL(query));
    for(ll i = 0; i < Q; i++) {
        swap(get<0>(query.at(i)), get<1>(query.at(i)));
    }
    vector<ll> last(550000, -1);
    BIT<ll> Z(N + 1);
    ll rindex = 1;
    vector<pair<ll, ll>> ans(Q);
    for(ll q = 0; q < Q; q++) {
        for(ll i = rindex; i <= get<1>(query.at(q)); i++) {
            if(last.at(c.at(i)) != -1) {
                Z.add(last.at(c.at(i)), -1);
            }
            last.at(c.at(i)) = i;
            Z.add(i, 1);
        }
        ans.at(q).first = get<2>(query.at(q));
        ans.at(q).second = Z.sum(get<1>(query.at(q))) - Z.sum(get<0>(query.at(q)) - 1);
        rindex = get<1>(query.at(q));
    }

    sort(ALL(ans));

    for(ll i = 0; i < Q; i++) {
        cout << ans.at(i).second << endl;
    }

    return 0;
}