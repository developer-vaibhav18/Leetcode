class Solution {
private:
    bool isValid(int i,int j,int n,int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
public:
    int minimumObstacles(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size(),i,j;
        set<vector<int>> s;
        s.insert({0,0,0});
        vector<vector<int>> dp(n,vector<int>(m,n*m));        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        dp[0][0]=0;
        vector<vector<int>> t={{-1,0},{0,-1},{1,0},{0,1}};
        while(s.size()){
            vector<int> p=*s.begin();
            s.erase(s.begin());
            if(vis[p[1]][p[2]])continue;
            vis[p[1]][p[2]]=true;
            for(i=0;i<4;i++){
                int x=p[1]+t[i][0],y=p[2]+t[i][1];
                if(isValid(x,y,n,m)){
                    if(dp[x][y]>p[0]+v[x][y]){
                        dp[x][y]=p[0]+v[x][y];
                        s.insert({dp[x][y],x,y});
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};