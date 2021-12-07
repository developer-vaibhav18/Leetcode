class Solution {
private:
    vector<vector<int>> dp;
    bool helper(string &s,string &p,int i,int j,int l){
        if(i==-1 && j==-1)return true;
        if(j==-1)return false;
        
        if(i==-1){
            return j<l;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(p[j]=='*'){
            return dp[i][j]=helper(s,p,i,j-1,l) || helper(s,p,i-1,j,l);
        }
        if(p[j]=='?' || p[j]==s[i]){
            return dp[i][j]=helper(s,p,i-1,j-1,l);
        }
        return dp[i][j]=false;
    }
public:
    bool isMatch(string s, string p) {
        dp.resize(s.size(),vector<int>(p.size(),-1));
        int i=0;
        for(i=0;i<p.size() && p[i]=='*';i++);
        return helper(s,p,s.size()-1,p.size()-1,i);
    }
};