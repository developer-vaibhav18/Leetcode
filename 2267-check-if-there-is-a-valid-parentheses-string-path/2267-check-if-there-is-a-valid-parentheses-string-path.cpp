class Solution {
    int value(char ch){
        if(ch == '(')return 1;
        return -1;
    }
public:
    bool hasValidPath(vector<vector<char>>& g) {
        int n = g.size(), m = g[0].size();
        if(g[0][0]==')')return false;
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (n + m + 1)));
        
        dp[0][0][1] = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; ++j){
                for(int k = 0; k <= n+m; ++k){
                    if(dp[i][j][k]){
                        if(i+1<n){
                            int v = value(g[i + 1][j]);
                            if(k + v >= 0) 
                                dp[i+1][j][k+v] = 1;
                        }
                        if(j + 1 < m){
                            int v = value(g[i][j + 1]);
                            if(k + v >= 0) 
                                dp[i][j+1][k+v] = 1;
                        }
                    }
                }
            }
        }
        
        return dp[n-1][m-1][0];
    }
};