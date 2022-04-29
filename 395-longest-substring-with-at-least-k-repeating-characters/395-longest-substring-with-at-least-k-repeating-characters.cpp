class Solution {
bool check(vector<vector<int>> &a,int l,int r,int k){
    int i,j;
    for(i=0;i<26;i++){
        if(a[i][r+1]-a[i][l]>=k || a[i][r+1]-a[i][l]==0)continue;
        return false;
    }
    return true;
}
public:
    int longestSubstring(string s, int k) {
        int n=s.size(),i,j,ans=0;
        vector<vector<int>> a(26,vector<int>(n+1));
        a[s[0]-'a'][1]=1;
        for(i=1;i<n;i++){
            a[s[i]-'a'][i+1]++;
            for(j=0;j<26;j++){
                a[j][i+1]+=a[j][i];
            }
        }
        
        for(i=0;i<26;i++){
            int l=0,r=0;
            while(l<n && r<n){
                if(a[i][r+1]-a[i][l]>=k){
                    if(check(a,l,r,k)){
                        ans=max(ans, r-l+1);
                        r++;
                    }
                    else{
                        l++;
                    }
                }
                else{
                    r++;
                }
            }
        }
        return ans;
    }
};