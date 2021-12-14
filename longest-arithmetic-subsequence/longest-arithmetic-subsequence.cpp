class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), i, j, ans=1;
        // cout<<n;
        vector<unordered_map<int,int>> mp(n);
        
        for(i=1;i<n;i++){
            for(j=i-1;j>=0;j--){
                int d = nums[i]-nums[j];
                if(mp[j].find(d) != mp[j].end()){
                    mp[i][d] = max(mp[i][d],mp[j][d]+1);
                }
                else{
                    mp[i][d] = max(2,mp[i][d]);
                }
                ans = max(ans,mp[i][d]);
            }
        }
        
        return ans;
    }
};