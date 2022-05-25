class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int n=v.size(),i;
        int maxUntilNow=v[0],maxSum=v[0];
        
        for(i=1;i<n;i++){
            maxUntilNow=max(maxUntilNow+v[i], v[i]);
            maxSum=max(maxSum, maxUntilNow);
        }
        
        return maxSum;
    }
};