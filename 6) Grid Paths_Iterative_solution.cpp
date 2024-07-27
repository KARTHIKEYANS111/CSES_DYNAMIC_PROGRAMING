#include <bits/stdc++.h>
using namespace std;
 
// #define int long long
const int mod = 1e9 + 7;
#define endl "\n"
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    int n; cin >> n;

    vector<vector<char>>v(n, vector<char>(n));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];     
        }           
    }   

    if(v[0][0] == '*') {
        cout << 0 << endl;
        return 0;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            int left = 0, top = 0;

            if(i == 0 and j == 0) {
                dp[i][j] = 1;
                continue;
            }

            if(v[i][j] == '*') continue;

            if(i - 1 >= 0) {
                left += dp[i - 1][j];
            }

            if(j - 1 >= 0) {
                top += dp[i][j - 1];
            }

            dp[i][j] = (top + left) % mod;
        }
    }

    cout << dp[n - 1][n - 1] << endl;

    return 0;
}
