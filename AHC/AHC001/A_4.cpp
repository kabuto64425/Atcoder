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

void spreadLeft(const ll index, const ll cap, const ll r, vector<tuple<ll, ll, ll, ll>> &candidate, const vector<ll> keyList, const unordered_map<ll, ll> &limitMap2) {
    tuple<ll, ll, ll, ll> &elmAbcd = candidate.at(index);
    ll width = get<2>(elmAbcd) - get<0>(elmAbcd);
    ll height = get<3>(elmAbcd) - get<1>(elmAbcd);
    // 左
    ll left = min(max(r / height - width, 0LL), cap);
    
    ll my1 = get<1>(elmAbcd);
    ll my2 = get<3>(elmAbcd);

    ll key1 = *lower_bound(keyList.begin(), keyList.end(), my1);
    ll key2 = *(upper_bound(keyList.begin(), keyList.end(), my2) - 1);

    //ll key1 = limitMap.lower_bound(my1)->first;
    //ll key2 = prev(limitMap.upper_bound(my2))->first;
    
    ll leftLimit = 0;
    if(key1 <= key2) {
        leftLimit = max(limitMap2.at(key1), limitMap2.at(key2));
    }

    get<0>(elmAbcd) = max(get<0>(elmAbcd) - left, leftLimit);
}

void spreadUp(const ll index, const ll cap, const ll r, vector<tuple<ll, ll, ll, ll>> &candidate, const vector<ll> keyList, const unordered_map<ll, ll> &limitMap2) {
    tuple<ll, ll, ll, ll> &elmAbcd = candidate.at(index);
    ll width = get<2>(elmAbcd) - get<0>(elmAbcd);
    ll height = get<3>(elmAbcd) - get<1>(elmAbcd);
    // 上
    ll up = min(max(r / width - height, 0LL), cap);
    
    ll mx1 = get<0>(elmAbcd);
    ll mx2 = get<2>(elmAbcd);

    ll key1 = *lower_bound(keyList.begin(), keyList.end(), mx1);
    ll key2 = *(upper_bound(keyList.begin(), keyList.end(), mx2) - 1);

    ll upLimit = 0;
    if(key1 <= key2) {
        upLimit = max(limitMap2.at(key1), limitMap2.at(key2));
    }

    get<1>(elmAbcd) = max(get<1>(elmAbcd) - up, upLimit);
}

void spreadRight(const ll index, const ll cap, const ll r, vector<tuple<ll, ll, ll, ll>> &candidate, const vector<ll> keyList, const unordered_map<ll, ll> &limitMap2) {
    tuple<ll, ll, ll, ll> &elmAbcd = candidate.at(index);
    ll width = get<2>(elmAbcd) - get<0>(elmAbcd);
    ll height = get<3>(elmAbcd) - get<1>(elmAbcd);
    // 右
    ll right = min(max(r / height - width, 0LL), cap);

    ll my1 = get<1>(elmAbcd);
    ll my2 = get<3>(elmAbcd);

    ll key1 = *lower_bound(keyList.begin(), keyList.end(), my1);
    ll key2 = *(upper_bound(keyList.begin(), keyList.end(), my2) - 1);

    ll rightLimit = 10000LL;
    if(key1 <= key2) {
        rightLimit = min(limitMap2.at(key1), limitMap2.at(key2));
    }

    get<2>(elmAbcd) = min(get<2>(elmAbcd) + right, rightLimit);
}

void spreadDown(const ll index, const ll cap, const ll r, vector<tuple<ll, ll, ll, ll>> &candidate, const vector<ll> keyList, const unordered_map<ll, ll> &limitMap2) {
    tuple<ll, ll, ll, ll> &elmAbcd = candidate.at(index);
    ll width = get<2>(elmAbcd) - get<0>(elmAbcd);
    ll height = get<3>(elmAbcd) - get<1>(elmAbcd);
    // 下
    ll down = min(max(r / width - height, 0LL), cap);
    
    ll mx1 = get<0>(elmAbcd);
    ll mx2 = get<2>(elmAbcd);

    ll key1 = *lower_bound(keyList.begin(), keyList.end(), mx1);
    ll key2 = *(upper_bound(keyList.begin(), keyList.end(), mx2) - 1);

    ll downLimit = 10000LL;
    if(key1 <= key2) {
        downLimit = min(limitMap2.at(key1), limitMap2.at(key2));
    }

    get<3>(elmAbcd) = min(get<3>(elmAbcd) + down, downLimit);
}

vector<function<void(ll, ll, ll, vector<tuple<ll, ll, ll, ll>>&, vector<ll>&, unordered_map<ll, ll>&)>> controlls{spreadLeft, spreadUp, spreadRight, spreadDown};

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

void spreadElmAbcd(ll split, ll index, ll r, tuple<ll, ll, ll, ll> &elmAbcd, vector<tuple<ll, ll, ll, ll>> &candidate) {

    ll mx1 = get<0>(elmAbcd);
    ll mx2 = get<2>(elmAbcd);

    ll my1 = get<1>(elmAbcd);
    ll my2 = get<3>(elmAbcd);
    
    unordered_map<ll, ll> leftLimitMap;
    // 番兵的な
    leftLimitMap[-1] = 10000LL;
    leftLimitMap[10001] = 10000LL;

    for(ll j = 0; j < n; j++) {
        if(index == j) {
            continue;
        }

        // 自身より右にあるものは無視
        ll ex1 = get<0>(candidate.at(j));
        
        if(ex1 >= mx2) {
            continue;
        }
        
        ll ey1 = get<1>(candidate.at(j));
        ll ey2 = get<3>(candidate.at(j));

        ll ex2 = get<2>(candidate.at(j));
        
        ll key;

        if(my1 >= ey2) {
            // 自身のほうが下
            key = ey2 - 1;
        } else if(ey1 >= my2) {
            // 自身のほうが上
            key = ey1 + 1;
        } else {
            key = my1;
        }
        if(!leftLimitMap.count(key)) {
           leftLimitMap[key] = 0;
        }
        leftLimitMap[key] = max(leftLimitMap[key], ex2);
    }

    vector<pair<ll, ll>> leftLimits1;
    vector<pair<ll, ll>> leftLimits2;

    for(pair<ll, ll> p : leftLimitMap) {
        if(p.first <= my1 - 1) {
            leftLimits1.push_back({p.first, p.second});
        } else {
            leftLimits2.push_back({p.first, p.second});
        }
    }

    sort(leftLimits1.begin(), leftLimits1.end());
    sort(leftLimits2.begin(), leftLimits2.end());

    for(ll i = (ll)leftLimits1.size() - 1LL; i >= 1; i--) {
        leftLimits1.at(i - 1).second = max(leftLimits1.at(i - 1).second, leftLimits1.at(i).second);
    }

    for(ll i = 0; i <= (ll)leftLimits2.size() - 2LL; i++) {
        leftLimits2.at(i + 1).second = max(leftLimits2.at(i + 1).second, leftLimits2.at(i).second);
    }

    for(const pair<ll, ll> &p : leftLimits1) {
        leftLimitMap.at(p.first) = p.second;
    }
    for(const pair<ll, ll> &p : leftLimits2) {
        leftLimitMap.at(p.first) = p.second;
    }

    vector<ll> leftLimitsKeyList(leftLimits1.size() + leftLimits2.size());
    for(ll i = 0; i < leftLimits1.size(); i++) {
        leftLimitsKeyList.at(i) = leftLimits1.at(i).first;
    }
    for(ll i = 0; i < leftLimits2.size(); i++) {
        leftLimitsKeyList.at(leftLimits1.size() + i) = leftLimits2.at(i).first;
    }

    unordered_map<ll, ll> upLimitMap;
    // 番兵的な
    upLimitMap[-1] = 10000LL;
    upLimitMap[10001] = 10000LL;

    for(ll j = 0; j < n; j++) {
        if(index == j) {
            continue;
        }

        // 自身より下にあるものは無視
        ll ey1 = get<1>(candidate.at(j));
        
        if(ey1 >= my2) {
            continue;
        }

        ll ex1 = get<0>(candidate.at(j));
        ll ex2 = get<2>(candidate.at(j));
        
        ll ey2 = get<3>(candidate.at(j));

        ll key;

        if(mx1 >= ex2) {
            // 自身のほうが右
            key = ex2 - 1;
        } else if(ex1 >= mx2) {
            // 自身のほうが左
            key = ex1 + 1;
        } else {
            key = mx1;
        }
        if(!upLimitMap.count(key)) {
           upLimitMap[key] = 0;
        }
        upLimitMap[key] = max(upLimitMap[key], ey2);
    }

    vector<pair<ll, ll>> upLimits1;
    vector<pair<ll, ll>> upLimits2;

    for(pair<ll, ll> p : upLimitMap) {
        if(p.first <= mx1 - 1) {
            upLimits1.push_back({p.first, p.second});
        } else {
            upLimits2.push_back({p.first, p.second});
        }
    }

    sort(upLimits1.begin(), upLimits1.end());
    sort(upLimits2.begin(), upLimits2.end());

    for(ll i = (ll)upLimits1.size() - 1LL; i >= 1; i--) {
        upLimits1.at(i - 1).second = max(upLimits1.at(i - 1).second, upLimits1.at(i).second);
    }

    for(ll i = 0; i <= (ll)upLimits2.size() - 2LL; i++) {
        upLimits2.at(i + 1).second = max(upLimits2.at(i + 1).second, upLimits2.at(i).second);
    }

    for(const pair<ll, ll> &p : upLimits1) {
        upLimitMap.at(p.first) = p.second;
    }
    for(const pair<ll, ll> &p : upLimits2) {
        upLimitMap.at(p.first) = p.second;
    }

    vector<ll> upLimitsKeyList(upLimits1.size() + upLimits2.size());
    for(ll i = 0; i < upLimits1.size(); i++) {
        upLimitsKeyList.at(i) = upLimits1.at(i).first;
    }
    for(ll i = 0; i < upLimits2.size(); i++) {
        upLimitsKeyList.at(upLimits1.size() + i) = upLimits2.at(i).first;
    }

    unordered_map<ll, ll> rightLimitMap;
    // 番兵的な
    rightLimitMap[-1] = 0LL;
    rightLimitMap[10001] = 0LL;

    for(ll j = 0; j < n; j++) {
        if(index == j) {
            continue;
        }

        // 自身より左にあるものは無視
        ll ex2 = get<2>(candidate.at(j));
        
        if(mx1 >= ex2) {
            continue;
        }

        ll ey1 = get<1>(candidate.at(j));
        ll ey2 = get<3>(candidate.at(j));

        ll ex1 = get<0>(candidate.at(j));

        ll key;
        
        if(my1 >= ey2) {
            // 自身のほうが下
            key = ey2 - 1;
        } else if(ey1 >= my2) {
            // 自身のほうが上
            key = ey1 + 1;
        } else {
            key = my1;
        }
        if(!rightLimitMap.count(key)) {
           rightLimitMap[key] = 10000LL;
        }
        rightLimitMap[key] = min(rightLimitMap[key], ex1);
    }

    vector<pair<ll, ll>> rightLimits1;
    vector<pair<ll, ll>> rightLimits2;

    for(pair<ll, ll> p : rightLimitMap) {
        if(p.first <= my1 - 1) {
            rightLimits1.push_back({p.first, p.second});
        } else {
            rightLimits2.push_back({p.first, p.second});
        }
    }

    sort(rightLimits1.begin(), rightLimits1.end());
    sort(rightLimits2.begin(), rightLimits2.end());

    for(ll i = (ll)rightLimits1.size() - 1LL; i >= 1; i--) {
        rightLimits1.at(i - 1).second = min(rightLimits1.at(i - 1).second, rightLimits1.at(i).second);
    }

    for(ll i = 0; i <= (ll)rightLimits2.size() - 2LL; i++) {
        rightLimits2.at(i + 1).second = min(rightLimits2.at(i + 1).second, rightLimits2.at(i).second);
    }

    for(const pair<ll, ll> &p : rightLimits1) {
        rightLimitMap.at(p.first) = p.second;
    }
    for(const pair<ll, ll> &p : rightLimits2) {
        rightLimitMap.at(p.first) = p.second;
    }

    vector<ll> rightLimitsKeyList(rightLimits1.size() + rightLimits2.size());
    for(ll i = 0; i < rightLimits1.size(); i++) {
        rightLimitsKeyList.at(i) = rightLimits1.at(i).first;
    }
    for(ll i = 0; i < rightLimits2.size(); i++) {
        rightLimitsKeyList.at(rightLimits1.size() + i) = rightLimits2.at(i).first;
    }

    unordered_map<ll, ll> downLimitMap;
    // 番兵的な
    downLimitMap[-1] = 0LL;
    downLimitMap[10001] = 0LL;

    for(ll j = 0; j < n; j++) {
        if(index == j) {
            continue;
        }

        ll ey2 = get<3>(candidate.at(j));
        // 自身より上にあるものは無視
        if(my1 >= ey2) {
            continue;
        }

        ll ex1 = get<0>(candidate.at(j));
        ll ex2 = get<2>(candidate.at(j));

        ll ey1 = get<1>(candidate.at(j));

        ll key;
        
        if(mx1 >= ex2) {
            // 自身のほうが右
            key = ex2 - 1;
        } else if(ex1 >= mx2) {
            // 自身のほうが左
            key = ex1 + 1;
        } else {
            key = mx1;
        }
        if(!downLimitMap.count(key)) {
           downLimitMap[key] = 10000LL;
        }
        downLimitMap[key] = min(downLimitMap[key], ey1);
    }

    vector<pair<ll, ll>> downLimits1;
    vector<pair<ll, ll>> downLimits2;

    for(pair<ll, ll> p : downLimitMap) {
        if(p.first <= mx1 - 1) {
            downLimits1.push_back({p.first, p.second});
        } else {
            downLimits2.push_back({p.first, p.second});
        }
    }

    sort(downLimits1.begin(), downLimits1.end());
    sort(downLimits2.begin(), downLimits2.end());

    for(ll i = (ll)downLimits1.size() - 1LL; i >= 1; i--) {
        downLimits1.at(i - 1).second = min(downLimits1.at(i - 1).second, downLimits1.at(i).second);
    }

    for(ll i = 0; i <= (ll)downLimits2.size() - 2LL; i++) {
        downLimits2.at(i + 1).second = min(downLimits2.at(i + 1).second, downLimits2.at(i).second);
    }

    for(const pair<ll, ll> &p : downLimits1) {
        downLimitMap.at(p.first) = p.second;
    }
    for(const pair<ll, ll> &p : downLimits2) {
        downLimitMap.at(p.first) = p.second;
    }

    vector<ll> downLimitsKeyList(downLimits1.size() + downLimits2.size());
    for(ll i = 0; i < downLimits1.size(); i++) {
        downLimitsKeyList.at(i) = downLimits1.at(i).first;
    }
    for(ll i = 0; i < downLimits2.size(); i++) {
        downLimitsKeyList.at(downLimits1.size() + i) = downLimits2.at(i).first;
    }

    ll dist = 10000 / split;
    ll initial = 10000 % split + dist;

    ll width = get<2>(elmAbcd) - get<0>(elmAbcd);
    ll height = get<3>(elmAbcd) - get<1>(elmAbcd);
    for(ll cap = initial; cap <= 10000; cap += dist) {
        controlls.at(0)(index, cap, r, candidate, leftLimitsKeyList, leftLimitMap);
        controlls.at(1)(index, cap, r, candidate, upLimitsKeyList, upLimitMap);
        controlls.at(2)(index, cap, r, candidate, rightLimitsKeyList, rightLimitMap);
        controlls.at(3)(index, cap, r, candidate, downLimitsKeyList, downLimitMap);
    }
}

int main(){
    clock_t start = clock();
    cin >> n;
    vector<tuple<ll, ll, ll>> xyr(n);
    for(auto &elm : xyr) {
        cin >> get<0>(elm) >> get<1>(elm) >> get<2>(elm);
    }

    vector<tuple<ll, ll, ll, ll>> abcd(n);
    for(ll i = 0; i < n; i++) {
        ll x = get<0>(xyr.at(i));
        ll y = get<1>(xyr.at(i));
        abcd.at(i) = {x, y, x + 1, y + 1};
    }

    ll topScore = 0;
    vector<tuple<ll, ll, ll, ll>> ans(n);

    for(ll split = 1; split <= 30; split++) {
        vector<tuple<ll, ll, ll, ll>> candidate = abcd;
        for(ll i = 0; i < n; i++) {
            tuple<ll, ll, ll, ll> &elmAbcd = candidate.at(i);
            ll r = get<2>(xyr.at(i));
            spreadElmAbcd(split, i, r, elmAbcd, candidate);
        }
        ll score = culc(n, xyr, candidate);
        if(score > topScore) {
            topScore = score;
            ans = candidate;
        }
    }

    std::random_device seed_gen;
    std::mt19937 engine {seed_gen()};

    vector<ll> vec(n);
    iota(vec.begin(), vec.end(), 0);

    const ll m = min(n, 30LL);


    /*while((long double)(clock() - start) / CLOCKS_PER_SEC < 4.8) {
        vector<ll> choice;
        sample(vec.begin(), vec.end(), std::back_inserter(choice), m, engine);

        vector<tuple<ll, ll, ll, ll>> candidate = ans;

        for(const ll index : choice) {
            tuple<ll, ll, ll, ll> &elmAbcd = candidate.at(index);
            elmAbcd = {get<0>(xyr.at(index)), get<1>(xyr.at(index)), get<0>(xyr.at(index)) + 1, get<1>(xyr.at(index)) + 1};
            ll r = get<2>(xyr.at(index));
            spreadElmAbcd(rand() % 49 + 1, index, r, elmAbcd, candidate);
        }

        ll score = culc(n, xyr, candidate);
        if(score > topScore) {
            topScore = score;
            ans = candidate;
        }
    }*/

    for(const auto &elm : ans) {
        cout << get<0>(elm) << " " << get<1>(elm) << " " << get<2>(elm) << " " << get<3>(elm) << endl;
    }
    return 0;
}