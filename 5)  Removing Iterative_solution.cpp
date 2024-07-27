#include <bits/stdc++.h>
using namespace std;
 
// #define int long long
#define endl "\n"
 
int n;
int dp[1000001];

 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    cin >> n;

    for(int i = 1; i <= 9; i++) dp[i] = 1;


    for(int i = 9; i <= n; i++) {
        int cur = i;
        int minimum_count = INT_MAX;
        while(cur > 0) {
            if(cur % 10 != 0) minimum_count = min(minimum_count, 1 + dp[i - cur % 10]);
            cur /= 10;
        } 
        dp[i] = minimum_count;
    }
    
    cout << dp[n] << endl;


    return 0;
}
