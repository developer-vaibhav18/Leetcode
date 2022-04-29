class Solution {
public:
    int minSwap(vector<int>& v1, vector<int>& v2) {
        int n=v1.size(),i;
        int dp[2]={0,1};
        for(i=n-2;i>=0;i--){
            int dp2[2];
            dp2[0]=dp2[1]=n+1;
            if(v1[i]<v1[i+1] && v2[i]<v2[i+1]){
                dp2[0]=dp[0];
                dp2[1]=dp[1]+1;
            }
            if(v1[i]<v2[i+1] && v2[i]<v1[i+1]){
                dp2[1]=min(dp2[1],dp[0]+1);
                dp2[0]=min(dp2[0],dp[1]);
            }
            dp[0]=dp2[0];
            dp[1]=dp2[1];
        }
        return min(dp[0],dp[1]);
    }
};