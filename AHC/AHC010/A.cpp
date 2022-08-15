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

const vector<vector<ll>> to = {
    {1, 0, -1, -1},
    {3, -1, -1, 0},
    {-1, -1, 3, 2},
    {-1, 2, 1, -1},
    {1, 0, 3, 2},
    {3, 2, 1, 0},
    {2, -1, 0, -1},
    {-1, 3, -1, 1},
};

vector<ll> rot = {1
,2
,3
,0
,5
,4
,7
,6};

const vector<ll> di = {0, -1, 0, 1};
const vector<ll> dj = {-1, 0, 1, 0}; 

ll culc(vector<vector<ll>> tiles) {
    vector<vector<vector<bool>>> flags(30, vector<vector<bool>>(30, vector<bool>(4)));
    vector<vector<vector<ll>>> ds(30, vector<vector<ll>>(30, vector<ll>(4)));
    for(ll si = 0; si < 30; si++) {
        for(ll sj = 0; sj < 30; sj++) {
            for(ll sd = 0; sd < 4; sd++) {
                if(flags.at(si).at(sj).at(sd)) {
                    continue;
                }
                flags.at(si).at(sj).at(sd) = true;
                // (si, sj) のタイルに sd 方向のタイルから侵入した状態からスタートして環状線の長さを求める
                ll i = si;
                ll j = sj;
                ll d = sd;
                ll length = 0;
                while(true) {
                    ll d2 = to[tiles[i][j]][d];
                    if (d2 == -1) break;
                    i += di[d2];
                    j += dj[d2];
                    if (i < 0 || i >= 30 || j < 0 || j >= 30) break;
                    d = (d2 + 2) % 4;
                    length += 1;
                    flags.at(i).at(j).at(d) = true;
                    if (i == si && j == sj && d == sd) {
                        ds.at(si).at(sj).at(sd) = length;
                        break;
                    }
                }
            }
            
        }
    }

    vector<ll> vec;
    ll count = 0;
    for(ll i = 0; i < 30; i++) {
        for(ll j = 0; j < 30; j++) {
            for(ll d = 0; d < 4; d++) {
                if(ds.at(i).at(j).at(d) != 0) {
                    count++;
                }
                vec.push_back(ds.at(i).at(j).at(d));
            }
        }
    }
    sort(ALL(vec), greater<ll>());
    
    ll score = vec.at(0) * vec.at(2);
    return score;
}

int main(){
    vector<string> t(30);
    for(ll i = 0; i < 30; i++) {
        cin >> t.at(i);
    }
    vector<vector<ll>> tiles(30, vector<ll>(30));
    for(ll i = 0; i < 30; i++) {
        for(ll j = 0; j < 30; j++) {
            tiles.at(i).at(j) = (ll)(t.at(i).at(j) - '0');
        }
    }

    ll score1 = culc(tiles);

    clock_t start = clock();

    random_device seed_gen;
    mt19937_64 rnd(seed_gen());
    uniform_int_distribution<ll> dist_N(0, 5);
    vector<vector<ll>> vec(30, vector<ll>(30));

    while((long double)(clock() - start) / CLOCKS_PER_SEC < 1.88) {
        vector<vector<ll>> vec2 = vec;
        for(ll i = 0; i < 30; i++) {
            for(ll j = 0; j < 30; j++) {
                if(dist_N(rnd) == 2) {
                    vec2.at(i).at(j) = ((vec2.at(i).at(j) == 1)? 0 : 1);
                }
            }
        }
    
        vector<vector<ll>> tiles2(30, vector<ll>(30));
        for(ll i = 0; i < 30; i++) {
            for(ll j = 0; j < 30; j++) {
                if(vec2.at(i).at(j) == 1) {
                    ll x = rot.at((ll)(t.at(i).at(j) - '0'));
                    tiles2.at(i).at(j) = x;
                } else {
                    tiles2.at(i).at(j) = (ll)(t.at(i).at(j) - '0');
                }
            }
        }
        ll score2 = culc(tiles2);
        if(score2 > score1) {
            score1 = score2;
            vec = vec2;
        }
    }

    for(ll i = 0; i < 30; i++) {
        for(ll j = 0; j < 30; j++) {
            cout << vec.at(i).at(j);
        }
    }
    cout << endl;
    return 0;
}