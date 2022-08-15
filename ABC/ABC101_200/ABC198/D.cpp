#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

// nPnの順列に対して処理を実行する
void foreach_permutation(int n, std::function<void(int *)> f) {
  int indexes[n];
  for (int i = 0; i < n; i++) indexes[i] = i;
  do {
    f(indexes);
  } while (std::next_permutation(indexes, indexes + n));
}

// nPkの順列に対して処理を実行する
void foreach_permutation(int n, int k, std::function<void(int *)> f) {
  foreach_comb(n, k, [&](int *c_indexes) {
    foreach_permutation(k, [&](int *p_indexes) {
      int indexes[k];
      for (int i = 0; i < k; i++) {
        indexes[i] = c_indexes[p_indexes[i]];
      }
      f(indexes);
    });
  });
}

vector<vector<ll>> enumerationPermutations(ll n, ll r) {
    vector<vector<ll>> res;
    foreach_permutation(n, r, [&r, &res](int *indexes) {
        vector<ll> vec(r);
        for(ll i = 0; i < r; i++) {
            vec.at(i) = indexes[i];
        }
        res.push_back(vec);
    });
    return res;
}

int main(){
    string S1;
    string S2;
    string S3;

    cin >> S1;
    cin >> S2;
    cin >> S3;

    set<char> mojiSet;
    for(const char &c : S1) {
        mojiSet.insert(c);
    }
    for(const char &c : S2) {
        mojiSet.insert(c);
    }
    for(const char &c : S3) {
        mojiSet.insert(c);
    }
    if(mojiSet.size() > 10) {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }

    vector<int> mojiVector(mojiSet.begin(), mojiSet.end());
    
    vector<vector<ll>> permutations = enumerationPermutations(10, mojiVector.size());
    for(const vector<ll> &permutation : permutations) {
        map<char, ll> numMap;
        for(ll i = 0; i < mojiVector.size(); i++) {
            numMap[mojiVector.at(i)] = permutation.at(i);
        }

        string N1, N2, N3;
        for(const char &c : S1) {
            N1 += (char) (numMap[c] + '0');
        }
        for(const char &c : S2) {
            N2 += (char) (numMap[c] + '0');
        }
        for(const char &c : S3) {
            N3 += (char) (numMap[c] + '0');
        }
        if(N1.at(0) == '0' or N2.at(0) == '0' or N3.at(0) == '0') {
            continue;
        }
        
        ll num1 = stoll(N1);
        ll num2 = stoll(N2);
        ll num3 = stoll(N3);
        if(num1 + num2 == num3) {
            cout << N1 << endl;
            cout << N2 << endl;
            cout << N3 << endl;
            return 0;
        }
    }

    cout << "UNSOLVABLE" << endl;
    return 0;
}