class Solution {
public:
    int maximumANDSum(vector<int>& v, int m) {
        int n=v.size(),i;
        pair<int,int> dp[1<<18];
        dp[0]={0,0};
        for(int i=1;i<(1<<n);i++){
            dp[i]={INT_MIN,INT_MIN};
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    int mask=(1<<j)^i;
                    int f=dp[mask].first,s=dp[mask].second;
                    for(int k=1;k<=2*m;k+=2){
                        if(((1<<k)&f)==0){
                            int nf=(1<<k)^f,ns=s+(((k+1)/2)&v[j]);
                            if(ns>dp[i].second){
                                dp[i]={nf,ns};
                            }
                        }
                        else if(((1<<(k+1))&f)==0){
                            int nf=(1<<(k+1))^f,ns=s+(((k+1)/2)&v[j]);
                            if(ns>dp[i].second){
                                dp[i]={nf,ns};
                            }
                        }
                    }
                }
            }
        }
        return dp[(1<<n)-1].second;
    }
};