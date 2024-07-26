#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mod = 1e9 + 7;
int n; 
int dp[1000001];

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        for(int x = 1; x <= 6; x++) {
            if(i - x >= 0) {
                dp[i] = (dp[i] + dp[i - x]) % mod;
            }
        }
    }

    cout << dp[n] << endl;
}