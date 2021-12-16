class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long i,n=nums.size(),s=accumulate(nums.begin(),nums.end(),0),mn[2]={INT_MAX,INT_MAX},mn2[2]={INT_MAX,INT_MAX};
        if(s%3==0)return s;
        for(i=0;i<n;i++){
            if(nums[i]%3==1 && mn[0]==INT_MAX){
                mn[0]=nums[i];
            }
            else if(nums[i]%3==1 && mn[1]==INT_MAX){
                mn[1]=nums[i];
            }
            if(nums[i]%3==2 && mn2[0]==INT_MAX){
                mn2[0]=nums[i];
            }
            else if(nums[i]%3==2 && mn2[1]==INT_MAX){
                mn2[1]=nums[i];
            }
        }
        if(s%3==1){
            return s-min(mn[0],mn2[0]+mn2[1]);
        }
        return s-min(mn2[0],mn[0]+mn[1]);
    }
};