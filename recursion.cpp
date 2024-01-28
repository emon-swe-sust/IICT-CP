#include<bits/stdc++.h>
using namespace std;

void initial() {
    #ifndef LEETCODE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int sum(int k) {
    cout << "K: " << k << endl;
    int ans = 0;
    if (k > 0) {
        ans = k + sum(k - 1);
        cout << "Ans: " << ans << endl;
    } else {
        ans = 0;
    }

    return ans;
}

int main() {
    initial();

    int result = sum(4);
    cout << result;
    return 0;
}