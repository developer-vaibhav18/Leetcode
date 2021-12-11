class Solution {
private:
    vector<vector<vector<vector<int>>>> dp;
    vector<vector<int>> v;
    int n;
    
    bool isValid(int i1,int j1,int i2,int j2){
        if(i1>=n || i2>=n || j1>=n || j2>=n)return false;
        
        if(v[i1][j1]==-1 || v[i2][j2]==-1)return false;
        
        return true;
    }
    
    int aux(int i1,int j1,int i2,int j2){
        if(!isValid(i1,j1,i2,j2))return INT_MIN;
        
        if(i1==n-1 && i2==n-1 && j1==n-1 && j2==n-1)return dp[i1][i1][i1][i1]=v[i1][j1];
        
        if(dp[i1][j1][i2][j2]!=-1)return dp[i1][j1][i2][j2];
        
        return dp[i1][j1][i2][j2] = max({aux(i1+1,j1,i2+1,j2),aux(i1,j1+1,i2+1,j2),aux(i1+1,j1,i2,j2+1),aux(i1,j1+1,i2,j2+1)}) + v[i1][j1] + v[i2][j2] - (i1==i2 && j1==j2)*v[i1][j1];
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        v=grid;
        n=v.size();
        dp.resize(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));

        return aux(0,0,0,0)<=0?0:dp[0][0][0][0];
        return 0;
        
    }
};