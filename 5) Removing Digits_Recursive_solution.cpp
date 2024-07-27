#include <bits/stdc++.h>
using namespace std;
 
// #define int long long
#define endl "\n"
 
int n;
int dp[1000001];

int recur(int x) {
    if(x == 0) {
        return 0;
    }

    int cur = x;
    int minimum_count = INT_MAX;

    if(dp[x] != -1) return dp[x];

    while(cur > 0) {
        if(cur % 10 != 0) minimum_count = min(minimum_count, (1 + recur(x - cur % 10)));
        cur /= 10;
    }

    return dp[x] = minimum_count;
}
 
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(dp, -1, sizeof(dp));

    cin >> n;

    cout << recur(n) << endl;;

 
    return 0;
}
