class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size();
        while(i<n){
            if(nums[i]==0){
                swap(nums[j],nums[i]);
                j++;
            }
            i++;
        }
        
        i=j;
        while(i<n){
            if(nums[i]==1){
                swap(nums[j],nums[i]);
                j++;
            }
            i++;
        }
    }
};