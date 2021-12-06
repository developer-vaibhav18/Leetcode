class Solution {
private:
    int dp[1000][1000];
    int aux(string &s,string &t,int i,int j){
        // cout<<i<<' '<<j<<"\n";
        if(j<=-1)return 1;
        if(i<j || i<=-1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=aux(s,t,i-1,j-1)+aux(s,t,i-1,j);
        }
        return dp[i][j]=aux(s,t,i-1,j);
    }
public:
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        memset(dp,-1,sizeof(dp));
        int ans=aux(s,t,n-1,m-1);
        
        if(ans==INT_MIN)return 0;
        return ans;
        
    }
};