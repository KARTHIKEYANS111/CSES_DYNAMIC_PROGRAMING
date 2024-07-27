#include <bits/stdc++.h>
using namespace std;
 
// #define int long long
#define endl "\n"

int n, x;
int price[1001], pages[1001]; 

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;
    
    for(int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> pages[i];           
    }
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j <= x; j++) {

            int w = price[i];
            int p = pages[i];

            int pick = 0;

            if(j >= w) {
                pick = p + dp[i + 1][j - w];
            }

            int notpick = dp[i + 1][j];

            dp[i][j] = max(pick, notpick);
        }
    }   

    cout << dp[0][x] << endl;

    return 0;
}
