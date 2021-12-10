class Solution {
private:
    int mod=1000000007;
    long long dp[1001],dp2[1001]; 
    
    long long fun(int n){
        if(n<=2)return n;
        
        if(dp[n]!=-1)return dp[n];
        
        return dp[n]=(fun(n-1) + fun(n-2) + 2*fun2(n-1))%mod;
    }
    
    long long fun2(int n){
        if(n<2)return 0;
        
        if(n==2)return 1;
        
        if(dp2[n]!=-1)return dp2[n];
        
        return dp2[n] = (fun2(n-1) + fun(n-2))%mod;
    }
    
public:
    int numTilings(int n) {
        
        memset(dp,-1,sizeof(dp));        
        memset(dp2,-1,sizeof(dp2));

        return fun(n);
    }
};