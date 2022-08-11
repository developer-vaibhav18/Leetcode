class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            while (num > 0 && num <= n && nums[num - 1] != num) {
                swap(nums[num - 1], num);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (i + 1 != nums[i]) return i + 1;
        }
        
        return n + 1;
    }
};