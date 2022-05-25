class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),i,j;
        
        for(i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                break;
            }
        }
        if(i){
            for(j=n-1;j>=0;j--){
                if(nums[j]>nums[i-1]){
                    swap(nums[j],nums[i-1]);
                    break;
                }
            }
        }
        reverse(nums.begin()+i,nums.end());
    }
};