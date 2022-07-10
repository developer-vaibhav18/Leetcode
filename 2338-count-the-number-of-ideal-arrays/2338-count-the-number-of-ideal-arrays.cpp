class Solution {
    const long long mod  = 1e9 + 7;
public:
    int idealArrays(int n, int m) {
        vector<vector<long long>> f(m + 1);
        for(int i = 1; i <= m; ++i){
            for(int  j = i + i; j <= m; j += i){
                f[j].push_back(i);
            }
        }
        
        vector<vector<long long>> dp(m + 1, vector<long long> (50));
        vector<long long> sz(50);
        dp[1][1] = 1;
        sz[1] = 1;
        for(int i = 2; i <= m; ++i){
            dp[i][1] = 1;
            // cout << i << '\n';
            for(int j = 0; j < f[i].size(); ++j){
                for(int k = 1; k < 20; ++k){
                    (dp[i][k + 1] += dp[f[i][j]][k]);
                }
            }
            for(int  k = 1; k < 20; ++k){
                (sz[k] += dp[i][k]) %= mod;
            }
        }
        
        vector<vector<long long>> dp2(50, vector<long long>(n + 1));
        long long ans = 0;
        for(int i = 0; i <= n; ++i){
            dp2[0][i] = 1;
        }
        for(int i = 1; i <= min(20, n); ++i){
            // cout << sz[i] << ' ';
            for(int j = i; j <= n; ++j){
                dp2[i][j] = (dp2[i - 1][j - 1])%mod;
                (dp2[i][j] += dp2[i][j - 1]) %= mod;
            }
            
            (ans += ((dp2[i][n] - dp2[i][n - 1] + mod) % mod * sz[i]) %mod) %= mod;
        }
        
        return ans;
    }
};