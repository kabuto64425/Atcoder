#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

// グローバル変数
ll n;

void spreadLeft(const ll index, const ll cap, const ll r, tuple<ll, ll, ll, ll> &elmAbcd, vector<tuple<ll, ll, ll, ll>> &candidate) {
    ll width = get<2>(elmAbcd) - get<0>(elmAbcd);
    ll height = get<3>(elmAbcd) - get<1>(elmAbcd);
    // 左
    ll left = min(max(r / height - width, 0LL), cap);
    ll leftLimit = 0;
    for(ll j = 0; j < n; j++) {
        if(index == j) {
            continue;
        }
        ll my1 = get<1>(elmAbcd);
        ll my2 = get<3>(elmAbcd);
        
        ll ey1 = get<1>(candidate.at(j));
        ll ey2 = get<3>(candidate.at(j));
        
        if(my1 >= ey2 || ey1 >= my2) {
            continue;
        }
        
        ll mx2 = get<2>(elmAbcd);
        ll ex1 = get<0>(candidate.at(j));
        
        if(ex1 >= mx2) {
            continue;
        }
        
        leftLimit = max(leftLimit, get<2>(candidate.at(j)));
    }
    get<0>(elmAbcd) = max(get<0>(elmAbcd) - left, leftLimit);
}

void spreadUp(const ll index, const ll cap, const ll r, tuple<ll, ll, ll, ll> &elmAbcd, const vector<tuple<ll, ll, ll, ll>> &candidate) {
    ll width = get<2>(elmAbcd) - get<0>(elmAbcd);
    ll height = get<3>(elmAbcd) - get<1>(elmAbcd);
    // 上
    ll up = min(max(r / width - height, 0LL), cap);
    
    ll upLimit = 0;
    
    for(ll j = 0; j < n; j++) {
        if(index == j) {
            continue;
        }
        ll mx1 = get<0>(elmAbcd);
        ll mx2 = get<2>(elmAbcd);
        
        ll ex1 = get<0>(candidate.at(j));
        ll ex2 = get<2>(candidate.at(j));
        
        if(mx1 >= ex2 || ex1 >= mx2) {
            continue;
        }
        
        ll my2 = get<3>(elmAbcd);
        ll ey1 = get<1>(candidate.at(j));
        
        if(ey1 >= my2) {
            continue;
        }
        
        upLimit = max(upLimit, get<3>(candidate.at(j)));
    }
    get<1>(elmAbcd) = max(get<1>(elmAbcd) - up, upLimit);
}

void spreadRight(const ll index, const ll cap, const ll r, tuple<ll, ll, ll, ll> &elmAbcd, vector<tuple<ll, ll, ll, ll>> &candidate) {
    ll width = get<2>(elmAbcd) - get<0>(elmAbcd);
    ll height = get<3>(elmAbcd) - get<1>(elmAbcd);
    // 右
    ll right = min(max(r / height - width, 0LL), cap);
    
    ll rightLimit = 10000LL;
    
    for(ll j = 0; j < n; j++) {
        if(index == j) {
            continue;
        }
        ll my1 = get<1>(elmAbcd);
        ll my2 = get<3>(elmAbcd);
        
        ll ey1 = get<1>(candidate.at(j));
        ll ey2 = get<3>(candidate.at(j));
        
        if(my1 >= ey2 || ey1 >= my2) {
            continue;
        }
        
        ll mx1 = get<0>(elmAbcd);
        ll ex2 = get<2>(candidate.at(j));
        
        if(mx1 >= ex2) {
            continue;
        }
        
        rightLimit = min(rightLimit, get<0>(candidate.at(j)));
    }
    
    get<2>(elmAbcd) = min(get<2>(elmAbcd) + right, rightLimit);
}

void spreadDown(const ll index, const ll cap, const ll r, tuple<ll, ll, ll, ll> &elmAbcd, vector<tuple<ll, ll, ll, ll>> &candidate) {
    ll width = get<2>(elmAbcd) - get<0>(elmAbcd);
    ll height = get<3>(elmAbcd) - get<1>(elmAbcd);
    // 下
    ll down = min(max(r / width - height, 0LL), cap);
    
    ll downLimit = 10000LL;
    
    for(ll j = 0; j < n; j++) {
        if(index == j) {
            continue;
        }
        ll mx1 = get<0>(elmAbcd);
        ll mx2 = get<2>(elmAbcd);
        
        ll ex1 = get<0>(candidate.at(j));
        ll ex2 = get<2>(candidate.at(j));
        
        if(mx1 >= ex2 || ex1 >= mx2) {
            continue;
        }
        
        ll my1 = get<1>(elmAbcd);
        ll ey2 = get<3>(candidate.at(j));
        
        if(my1 >= ey2) {
            continue;
        }
        
        downLimit = min(downLimit, get<1>(candidate.at(j)));
    }
    
    get<3>(elmAbcd) = min(get<3>(elmAbcd) + down, downLimit);
}

vector<function<void(ll, ll, ll, tuple<ll, ll, ll, ll>&, vector<tuple<ll, ll, ll, ll>>&)>> controlls{spreadLeft, spreadUp, spreadRight, spreadDown};

bool isHit(const tuple<ll, ll, ll, ll> rect1, const tuple<ll, ll, ll, ll> rect2) {
    ll mx1 = get<0>(rect1);
    ll my1 = get<1>(rect1);
    ll mx2 = get<2>(rect1);
    ll my2 = get<3>(rect1);

    ll ex1 = get<0>(rect2);
    ll ey1 = get<1>(rect2);
    ll ex2 = get<2>(rect2);
    ll ey2 = get<3>(rect2);

    if(mx1 < ex2 && ex1 < mx2 && my1 < ey2 && ey1 < my2) {
        return true;
    }
    return false;
}

ll culc(const ll n, const vector<tuple<ll, ll, ll>> xyr, const vector<tuple<ll, ll, ll, ll>> abcd) {

    /*for(ll i = 0; i <= n - 2; i++) {
        for(ll j = i + 1; j <= n - 1; j++) {
            tuple<ll, ll, ll, ll> rect1 = abcd.at(i);
            tuple<ll, ll, ll, ll> rect2 = abcd.at(j);
            if(isHit(rect1, rect2)) {
                return 0;
            }
        }
    }*/

    long double score = 0;
    for(ll i = 0; i < n; i++) {
        tuple<ll, ll, ll> elmXyr = xyr.at(i);
        tuple<ll, ll, ll, ll> elmAbcd = abcd.at(i);
        if(get<0>(elmAbcd) > get<0>(elmXyr) or get<2>(elmAbcd) <= get<0>(elmXyr) or get<1>(elmAbcd) > get<1>(elmXyr) or get<3>(elmAbcd) <= get<1>(elmXyr)) {
            continue;
        }
        ll s = abs(get<2>(elmAbcd) - get<0>(elmAbcd)) * abs(get<3>(elmAbcd) - get<1>(elmAbcd));
        ll r = get<2>(elmXyr);
        long double p = 1 - (1 - min(r, s) / (long double) max(r, s)) * (1 - min(r, s) / (long double) max(r, s));
        score += p;
    }
    score *= 1000000000;
    score /= n;
    return (long long)score;
}

vector<long double> culcEachSatisfaction(const ll n, const vector<tuple<ll, ll, ll>> xyr, const vector<tuple<ll, ll, ll, ll>> abcd) {

    vector<long double> eachSatisfaction(n, 0);
    for(ll i = 0; i <= n - 2; i++) {
        for(ll j = i + 1; j <= n - 1; j++) {
            tuple<ll, ll, ll, ll> rect1 = abcd.at(i);
            tuple<ll, ll, ll, ll> rect2 = abcd.at(j);
            if(isHit(rect1, rect2)) {
                return eachSatisfaction;
            }
        }
    }

    long double score = 0;
    for(ll i = 0; i < n; i++) {
        tuple<ll, ll, ll> elmXyr = xyr.at(i);
        tuple<ll, ll, ll, ll> elmAbcd = abcd.at(i);
        if(get<0>(elmAbcd) > get<0>(elmXyr) or get<2>(elmAbcd) <= get<0>(elmXyr) or get<1>(elmAbcd) > get<1>(elmXyr) or get<3>(elmAbcd) <= get<1>(elmXyr)) {
            continue;
        }
        ll s = abs(get<2>(elmAbcd) - get<0>(elmAbcd)) * abs(get<3>(elmAbcd) - get<1>(elmAbcd));
        ll r = get<2>(elmXyr);
        long double p = 1 - (1 - min(r, s) / (long double) max(r, s)) * (1 - min(r, s) / (long double) max(r, s));
        eachSatisfaction.at(i) = p;
    }
    return eachSatisfaction;
}

long double culcSatisfaction(ll index, const vector<tuple<ll, ll, ll>> xyr, const tuple<ll, ll, ll, ll> elmAbcd) {
    tuple<ll, ll, ll> elmXyr = xyr.at(index);
    if(get<0>(elmAbcd) > get<0>(elmXyr) or get<2>(elmAbcd) <= get<0>(elmXyr) or get<1>(elmAbcd) > get<1>(elmXyr) or get<3>(elmAbcd) <= get<1>(elmXyr)) {
        return 0;
    }
    ll s = abs(get<2>(elmAbcd) - get<0>(elmAbcd)) * abs(get<3>(elmAbcd) - get<1>(elmAbcd));
    ll r = get<2>(elmXyr);
    long double p = 1 - (1 - min(r, s) / (long double) max(r, s)) * (1 - min(r, s) / (long double) max(r, s));
    return p;
}

tuple<ll, ll, ll, ll> spreadElmAbcd(ll split, ll index, ll r, vector<tuple<ll, ll, ll, ll>> &candidate) {

    tuple<ll, ll, ll, ll> elmAbcd = candidate.at(index);

    ll dist = 10000 / split;
    ll initial = 10000 % split + dist;

    ll width = get<2>(elmAbcd) - get<0>(elmAbcd);
    ll height = get<3>(elmAbcd) - get<1>(elmAbcd);
    for(ll cap = initial; cap <= 10000; cap += dist) {
        controlls.at(0)(index, cap, r, elmAbcd, candidate);
        controlls.at(1)(index, cap, r, elmAbcd, candidate);
        controlls.at(2)(index, cap, r, elmAbcd, candidate);
        controlls.at(3)(index, cap, r, elmAbcd, candidate);
    }
    return elmAbcd;
}

int main(){
    clock_t start = clock();
    cin >> n;
    vector<tuple<ll, ll, ll>> xyr(n);
    for(auto &elm : xyr) {
        cin >> get<0>(elm) >> get<1>(elm) >> get<2>(elm);
    }

    cout << (long double)(start = clock()) / CLOCKS_PER_SEC << endl;

    vector<tuple<ll, ll, ll, ll>> abcd(n);
    for(ll i = 0; i < n; i++) {
        ll x = get<0>(xyr.at(i));
        ll y = get<1>(xyr.at(i));
        abcd.at(i) = {x, y, x + 1, y + 1};
    }

    vector<long double> eachSatisfaction = culcEachSatisfaction(n, xyr, abcd);

    ll topScore = 0;
    vector<tuple<ll, ll, ll, ll>> ans(n);
    ans = abcd;

    const vector<ll> splits{30, 15, 10, 5, 2, 1};

    for(ll split : splits) {
        for(ll i = 0; i < n; i++) {
            ll r = get<2>(xyr.at(i));
            tuple<ll, ll, ll, ll> elmAbcd = spreadElmAbcd(split, i, r, ans);
            long double satisfaction = culcSatisfaction(i, xyr, elmAbcd);
            if(satisfaction > eachSatisfaction.at(i)) {
                ans.at(i) = elmAbcd;
                eachSatisfaction.at(i) = satisfaction;
            }
        }
    }

    std::random_device seed_gen;
    std::mt19937 engine {seed_gen()};

    vector<ll> vec(n);
    iota(vec.begin(), vec.end(), 0);

    const ll m = n / 20;

    clock_t current = clock();

    while((long double)(clock() - start) / CLOCKS_PER_SEC < 4.88) {
        ll current2 = clock();
        cout << (long double)(current2 - current) / CLOCKS_PER_SEC << endl;
        current = current2;
        priority_queue<pair<long double, ll>, vector<pair<long double, ll>>, greater<pair<long double, ll>>> A;
        for(ll i = 0; i < n; i++) {
            A.push({eachSatisfaction.at(i), i});
        }
 
        vector<ll> choice;
 
        REP(i, (n + 19) / 20) {
            choice.push_back(A.top().second);
            A.pop();
        }
 
        sample(vec.begin(), vec.end(), std::back_inserter(choice), m, engine);
        choice.erase(unique(choice.begin(), choice.end()), choice.end());
        shuffle(choice.begin(), choice.end(), engine);
 
        vector<tuple<ll, ll, ll, ll>> candidate = ans;

        long double before = 0;
        long double after = 0;

        vector<long double> afterEachSatisfaction = eachSatisfaction;
 
        for(const ll index : choice) {
            before += eachSatisfaction.at(index);
            candidate.at(index) = {get<0>(xyr.at(index)), get<1>(xyr.at(index)), get<0>(xyr.at(index)) + 1, get<1>(xyr.at(index)) + 1};
            afterEachSatisfaction.at(index) = culcSatisfaction(index, xyr, candidate.at(index));
        }

        for(const ll index : choice) {

        
            ll r = get<2>(xyr.at(index));
            tuple<ll, ll, ll, ll> elmAbcd = spreadElmAbcd(50, index, r, candidate);
            if(culcSatisfaction(index, xyr, elmAbcd) > afterEachSatisfaction.at(index)) {
                afterEachSatisfaction.at(index) = culcSatisfaction(index, xyr, elmAbcd);
                candidate.at(index) = elmAbcd;
            }
        
            after += afterEachSatisfaction.at(index);
        }

        if(after > before) {
            eachSatisfaction = afterEachSatisfaction;
            ans = candidate;
        }
    }

    for(const auto &elm : ans) {
        cout << get<0>(elm) << " " << get<1>(elm) << " " << get<2>(elm) << " " << get<3>(elm) << endl;
    }
    return 0;
}