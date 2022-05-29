class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size(),i;
        int a[26]={0},mx=0,ans=0,j=0;
        
        for(i=0;i<n;i++){
            a[s[i]-'A']++;
            mx=max(mx, a[s[i]-'A']);
            
            while(i-j+1>mx+k){
                a[s[j]-'A']--;
                j++;
            }
            ans=max(ans, i-j+1);
        }
        return ans;
    }
};