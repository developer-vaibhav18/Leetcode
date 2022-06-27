class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4)return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = *prev(nums.end()) - *(nums.begin());
        
        for(int i = 0; i < 4; ++i){
            ans = min(ans, nums[n-(4 - i)] - nums[i]);
        }
        
        return ans;
    }
};