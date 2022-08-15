#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, N;
    cin >> X >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
      cin >> vec.at(i);
    }

    int index = 0;
    int res;
    while(true) {
        bool minusFlag = true;
        bool plusFlag = true;
        for(int i = 0; i < N; i++) {
            if(vec.at(i) == (X - index)) {
                minusFlag = false;
            }
            if(vec.at(i) == (X + index)) {
                plusFlag = false;
            }
            if(!minusFlag && !plusFlag) {

            }
        }
        if(minusFlag) {
            res = X - index;
            break;
        }
        if(plusFlag) {
            res = X + index;
            break;
        }
        index++;
    }
    cout << res << endl;
}