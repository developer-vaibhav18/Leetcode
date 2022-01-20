class Solution {
public:
    int longestValidParentheses(string s) {
        int c=0,ans=0,i,mn=s.size(),mx=-1,cur=0,n=s.size();
        int dp[n+1];
        // memset(dp,-1,sizeof(dp));
        dp[0]=-1;
        
        for(i=0;i<n;i++){
            if(s[i]=='('){
                c++;
                // if(dp[c]<=mx){
                    dp[c]=i;
                // }
            }
            else if(s[i]==')'){
                c--;
                if(c>=0){
                    if(dp[c]>=mx)
                        ans=max(ans,i-dp[c]);
                }
                else{
                    c=0;
                    dp[0]=i;
                    mx=i;
                }
            }
        }
        return ans;
    }
};