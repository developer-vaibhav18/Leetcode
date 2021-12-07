class Solution {
private:
    int dp[30][30][30][30];
    bool helper(string &s1,string &s2,int i1,int j1,int i2,int j2){
        if(i1>=j1)return s1[i1]==s2[i2];
        // cout<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<"\n";
        if(dp[i1][j1][i2][j2]!=-1)return dp[i1][j1][i2][j2];
        
        int i;
        for(i=i1;i<j1;i++){
            if(helper(s1,s2,i1,i,i2,i2+i-i1) && helper(s1,s2,i+1,j1,i2+i-i1+1,j2))return dp[i1][j1][i2][j2]=1;
            if(helper(s1,s2,i1,i,j2-(i-i1),j2) && helper(s1,s2,i+1,j1,i2,j2-(i-i1)-1))return dp[i1][j1][i2][j2]=1;  
        }
        return dp[i1][j1][i2][j2]=0;
    }
public:
    bool isScramble(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return helper(s1,s2,0,s1.size()-1,0,s2.size()-1);
    }
};