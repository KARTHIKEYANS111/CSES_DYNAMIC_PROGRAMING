#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ll long long
#define endl "\n"

const int mod = 1e9 + 7;

ll mod_add(ll a, ll b, ll m = mod) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
ll mod_sub(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
ll expo(ll a, ll b, ll mod) { ll res = 1; while (b > 0) { if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res; }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m; cin >> n >> m;

    vector<int>arr(n);
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(105, -1));
    
    
    function<int(int, int)> recur = [&](int idx, int prev) -> int {

        if(idx == n) {
            return 1;
        }

        if(dp[idx][prev] != -1) return dp[idx][prev];

        int ways = 0;

        if(arr[idx] != 0) {
            if(abs(prev - arr[idx]) <= 1) ways =  recur(idx + 1, arr[idx]);
        }
        else {
            if(prev > 1) {
                ways = mod_add(ways, recur(idx + 1, prev - 1));
            }
            ways = mod_add(ways, recur(idx + 1, prev));
            if(prev < m) {
                ways = mod_add(ways, recur(idx + 1, prev + 1));
            }
        }

        return dp[idx][prev] = ways; 

    };

    int ans = 0;
    if(arr[0] == 0) {
        for(int i  = 1; i <= m; i++) {
            ans = mod_add(ans, recur(1, i));
        }
    } else {
        ans = mod_add(ans, recur(1, arr[0]));
    }
    cout << ans << endl;
 
    return 0;
}
