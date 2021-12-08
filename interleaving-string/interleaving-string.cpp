class Solution {
private:
    int dp[101][101][2];
    int n,m,l;
    bool helper(string &s1,string &s2,string &s3,int i1,int i2,int i3,bool merge){
        
        if(i3==l)return true;
        if(i1==n && merge) return false;
        if(i2==m && !merge){
            // cout<<2;
            return false;
        }
        
        if(i1==n){
            while(i2<m){
                if(s2[i2++]!=s3[i3++])return false;
            }
            return true;
        }
        
        if(i2==m){
            while(i1<n){
                if(s1[i1++]!=s3[i3++])return false;
            }
            return true;
        }
        // cout<<i1<<" "<<i2<<" "<<merge<<"\n";
        
        if(dp[i1][i2][merge]!=-1)return dp[i1][i2][merge];
        
        int i,j,temp_i3=i3;
        if(i1==0 || merge){
            for(i=i1;i<n;i++){
                if(s3[temp_i3++]!=s1[i])break;
                int temp2_i3=temp_i3;
                for(j=i2;j<m;j++){
                    if(s2[j]!=s3[temp2_i3++])break;
                    if(helper(s1,s2,s3,i+1,j+1,temp2_i3,true))return dp[i1][i2][merge]=true;
                }
            }
        }
        
        if(i1==0 || !merge){
            temp_i3=i3;
            for(i=i2;i<m;i++){
                if(s2[i]!=s3[temp_i3++])break;
                int temp2_i3=temp_i3; 
                for(j=i1;j<n;j++){
                    if(s1[j]!=s3[temp2_i3++])break;
                    if(helper(s1,s2,s3,j+1,i+1,temp2_i3,false))return dp[i1][i2][merge]=true;
                }
            }
        }
        
        return dp[i1][i2][merge]=false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int i,j,k;
        n=s1.size(),m=s2.size(),l=s3.size();
        
        if(n+m != l)return false;
        
        // bool dp[n+1][m+1][l+1];
        
        memset(dp,-1,sizeof(dp));
        if(s1==""){
            return s2==s3;
        }
        if(s2=="")return s1==s3;
        // cout<<1;
        // if(helper(s1,s2,s3,0,0,0,true))return true; 
        // memset(dp,-1,sizeof(dp));
        return helper(s1,s2,s3,0,0,0,true);
        
//         for(i=0;i<m && s3[i]==s2[i];i++){
//             dp[0][i][i]=true;
//         }
        
//         for(i=0; i<n && s1[i]==s3[i]; i++){
             
//         }
    }
};