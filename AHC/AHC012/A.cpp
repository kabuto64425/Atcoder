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

struct Strawberry {
    ll x;
    ll y;
};

struct CakeCut {
    ll px;
    ll py;
    ll qx;
    ll qy;
};

ll compute_score(ll N, ll K, const vector<ll> &a, const vector<Strawberry> &Strawberries, const vector<CakeCut> &CakeCuts) {
    vector<vector<ll>> pieces;
    pieces.push_back(vector<ll>());
    for(ll i = 0; i < N; i++) {
        pieces.at(0).push_back(i);
    }
    for(const CakeCut &cut : CakeCuts) {
        vector<vector<ll>> new_pieces;
        for(ll i = 0; i < (ll)pieces.size(); i++) {
            vector<ll> left;
            vector<ll> right;
            for(ll j : pieces.at(i)) {
                Strawberry s = Strawberries.at(j);
                ll side = (cut.qx - cut.px) * (s.y - cut.py) - (cut.qy - cut.py) * (s.x - cut.px);
                if(side > 0) {
                    left.push_back(j);
                } else if (side < 0) {
                    right.push_back(j);
                }
            }
            if(left.size() > 0) {
                new_pieces.push_back(left);
            }
            if(right.size() > 0) {
                new_pieces.push_back(right);
            }
        }
        pieces = new_pieces;
    }
    vector<ll> b(10);
    for(vector<ll> &piece: pieces) {
        if(piece.size() >= 1 and piece.size() <= 10) {
            b[piece.size() - 1] += 1;
        }
    }
    ll num = 0;
    ll den = 0;
    for(ll d = 0; d < 10; d++) {
        num += min(a[d], b[d]);
        den += a[d];
    }
    ll score = round((1e6 * num) / (long double)den);
    return score;
}

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> a(10);
    for(ll i = 0; i < 10; i++) {
        cin >> a.at(i);
    }
    vector<Strawberry> strawberries(N);
    for(ll i = 0; i < N; i++) {
        cin >> strawberries.at(i).x;
        cin >> strawberries.at(i).y;
    }

    clock_t start = clock();

    ll highest = 0;
    vector<CakeCut> ans;
    random_device seed_gen;
    mt19937_64 rnd(seed_gen());

    uniform_int_distribution<ll> dist_k(0, K), dist_pq(-1000000000, 1000000000);
    while((long double)(clock() - start) / CLOCKS_PER_SEC < 2.5) {
        ll k = dist_k(rnd);
        vector<CakeCut> cakecuts(k);
        for(ll i = 0; i < k; i++) {
            cakecuts.at(i).px = dist_pq(rnd);
            cakecuts.at(i).py = dist_pq(rnd);
            cakecuts.at(i).qx = dist_pq(rnd);
            cakecuts.at(i).qy = dist_pq(rnd);
        }
        ll score = compute_score(N, K, a, strawberries, cakecuts);
        if(chmax(highest, score)) {
            ans = cakecuts;
        }
    }

    cout << ans.size() << endl;
    for(ll i = 0; i < (ll)ans.size(); i++) {
        cout << ans.at(i).px << " " << ans.at(i).py << " " << ans.at(i).qx << " " << ans.at(i).qy << endl;
    }
    return 0;
}