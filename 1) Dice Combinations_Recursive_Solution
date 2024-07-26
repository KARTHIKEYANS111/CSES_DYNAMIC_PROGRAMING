// The below is the recursive implementation of Dice Combinations problem

#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl "\n"
 
const int mod = 1e9 + 7;
int n; 
int dp[1000001];
 
int recur(int x, int n) {
 
    if(x == n) return 1;
    if(x > n) return 0;
 
    if(dp[x] != -1) return dp[x];
 
    int ways = 0;
 
    for(int i = 1; i <= 6; i++) {
        ways = (ways + recur(x + i, n)) % mod;
    }
 
    return dp[x] = ways;
 
}
 
signed main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;
    memset(dp, -1, sizeof(dp));
 
    cout << recur(0, n) << endl;
}
