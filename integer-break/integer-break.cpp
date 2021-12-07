class Solution {
private:
    int solver(int n,int dp[]){
        if(n==0)return 0;
        if(n==1)return 1;
        
        if(dp[n]!=-1)return dp[n];
        
        int i,ans=n;
        
        for(i=1;i<n;i++){
            ans=max(ans,solver(i,dp)*solver(n-i,dp));
        }
        return dp[n]=ans;
    }
public:
    int integerBreak(int n) {
        if(n<=3)return n-1;
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        return solver(n,dp);
    }
};