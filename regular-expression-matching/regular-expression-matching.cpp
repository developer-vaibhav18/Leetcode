class Solution {
private:
    int dp[20][30];
    bool helper(string &s,string &p,int i,int j,int l){
        // cout<<i<<" "<<j<<"\n";
        
        if(i<=-1 && j<=-1){
            return true;
        }
        if(j<=-1)return false;
        if(i<=-1){
            if(j<l)return true;
            return false;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(p[j]=='*'){
            if(helper(s,p,i,j-2,l))return dp[i][j]=true;
            
            if((s[i] == p[j-1] || p[j-1] == '.') && (helper(s,p,i-1,j,l)))
                return dp[i][j]=true; 
        }
        
        if(p[j]=='.' || p[j]==s[i]){
            return dp[i][j]=helper(s,p,i-1,j-1,l);
        }
        
        return false;
    }
public:
    bool isMatch(string s, string p) {
        int i=0;
        while(i<p.size()){
            // if(p[i]!='*')break;
            if(i+1<p.size() && p[i+1]=='*')i+=2;
            else break;
        }
        memset(dp,-1,sizeof(dp));
        // cout<<i;
        return helper(s,p,s.size()-1,p.size()-1,i);
    }
};